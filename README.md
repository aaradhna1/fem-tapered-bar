# fem-tapered-bar
FEM analysis of circular tapered bar under axial load
# Circular Tapered Bar FEM Analysis

## Objective
To determine axial displacement of a circular tapered bar using:
- Analytical method
- Finite Element Method (FEM)

---

## Theory

### Analytical Solution:
δ = (4PL) / (π E d1 d2)

---

## FEM Method:
- Bar divided into n elements
- Each element treated as uniform bar
- Midpoint diameter used
- Global stiffness matrix approach

---

## Procedure
1. Divide bar into n elements
2. Compute element stiffness matrix
3. Assemble global stiffness matrix
4. Apply boundary conditions
5. Solve for nodal displacements

---

## Results

## Results Comparison

| Elements (n) | FEM Displacement (m) | Analytical Displacement (m) | Error (%) |
|--------------|----------------------|------------------------------|-----------|
| 1 | 0.6053190331 | 0.6111549815 | 0.95% |
| 2 | 0.5148432739 | 0.6111549815 | 15.76% |
| 3 | 0.5590659144 | 0.6111549815 | 8.52% |
| 5 | 0.5895585139 | 0.6111549815 | 3.53% |
| 10 | 0.6053190331 | 0.6111549815 | 0.95% |

## Observation

As the number of elements increases, the FEM solution approaches the analytical solution. The percentage error decreases significantly, showing convergence of the FEM method.
---

## Conclusion
Finite Element Method provides an approximate solution which converges to the exact analytical result with mesh refinement.

---

## Tools Used
- C++
- MSYS2 Compiler
- VS Code
- GitHub
