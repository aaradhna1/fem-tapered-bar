#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double PI = 3.141592653589793;

// Gaussian Elimination Solver
vector<double> solveSystem(vector<vector<double>> A, vector<double> b)
{
    int n = b.size();

    // Forward Elimination
    for(int i=0;i<n;i++)
    {
        double pivot = A[i][i];

        for(int j=i;j<n;j++)
            A[i][j] /= pivot;

        b[i] /= pivot;

        for(int k=i+1;k<n;k++)
        {
            double factor = A[k][i];

            for(int j=i;j<n;j++)
                A[k][j] -= factor*A[i][j];

            b[k] -= factor*b[i];
        }
    }

    // Back Substitution
    vector<double> x(n);

    for(int i=n-1;i>=0;i--)
    {
        x[i] = b[i];

        for(int j=i+1;j<n;j++)
            x[i] -= A[i][j]*x[j];
    }

    return x;
}

int main()
{
    double L, P, E, d1, d2;
    int n;

    cout << "Enter Length L (m): ";
    cin >> L;

    cout << "Enter Load P (N): ";
    cin >> P;

    cout << "Enter Young's Modulus E (Pa): ";
    cin >> E;

    cout << "Enter Diameter d1 at Fixed End (m): ";
    cin >> d1;

    cout << "Enter Diameter d2 at Free End (m): ";
    cin >> d2;

    cout << "Enter Number of Elements n: ";
    cin >> n;

    int nodes = n + 1;
    double le = L / n;

    // Global stiffness matrix
    vector<vector<double>> K(nodes, vector<double>(nodes,0));

    // Assembly
    for(int e=0;e<n;e++)
    {
        double xm = (e + 0.5)*le;

        double de = d1 + ((d2-d1)/L)*xm;

        double Ae = PI*de*de/4.0;

        double k = Ae*E/le;

        K[e][e] += k;
        K[e][e+1] -= k;
        K[e+1][e] -= k;
        K[e+1][e+1] += k;
    }

    // Force vector
    vector<double> F(nodes,0);
    F[nodes-1] = P;

    // Reduced Matrix (u1 = 0)
    int r = nodes - 1;

    vector<vector<double>> Kred(r, vector<double>(r));
    vector<double> Fred(r);

    for(int i=1;i<nodes;i++)
    {
        Fred[i-1] = F[i];

        for(int j=1;j<nodes;j++)
            Kred[i-1][j-1] = K[i][j];
    }

    // Solve
    vector<double> ured = solveSystem(Kred, Fred);

    vector<double> u(nodes,0);

    for(int i=1;i<nodes;i++)
        u[i] = ured[i-1];

    // FEM displacement
    double deltaFEM = u[nodes-1];

    // Analytical displacement
    double deltaExact =
        (4.0*P*L)/(PI*E*d1*d2);

    double error =
        fabs(deltaExact-deltaFEM)/deltaExact*100.0;

    cout << fixed << setprecision(10);

    cout << "\n=================================\n";

    cout << "\nAnalytical Displacement = "
         << deltaExact << " m\n";

    cout << "FEM Displacement = "
         << deltaFEM << " m\n";

    cout << "Percentage Error = "
         << error << " %\n";

    cout << "\nNodal Displacements:\n";

    for(int i=0;i<nodes;i++)
    {
        cout << "Node "
             << i+1
             << " : "
             << u[i]
             << " m\n";
    }

    cout << "\nGlobal Stiffness Matrix:\n";

    for(int i=0;i<nodes;i++)
    {
        for(int j=0;j<nodes;j++)
        {
            cout << setw(15)
                 << K[i][j];
        }
        cout << endl;
    }

    cout << "\n=================================\n";

    return 0;
}