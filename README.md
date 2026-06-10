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

| Elements (n) | FEM Displacement | Analytical Displacement | Error % |
|--------------|------------------|--------------------------|---------|
| 1 | (fill) | (same value) | (calc) |
| 2 | (fill) | (same value) | (calc) |
| 3 | (fill) | (same value) | (calc) |

---

## Observation
As number of elements increases, FEM solution approaches analytical solution.

---

## Conclusion
Finite Element Method provides an approximate solution which converges to the exact analytical result with mesh refinement.

---

## Tools Used
- C++
- MSYS2 Compiler
- VS Code
- GitHub
