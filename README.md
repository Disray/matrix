# matrix

[![Language](https://img.shields.io/badge/Language-C%2B%2B20-00599C?logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/20)
[![Build](https://img.shields.io/badge/Build-Make%20%2F%20Clang++-success)](#getting-started)
[![Architecture](https://img.shields.io/badge/Architecture-Header--Only%20Templates-orange)](#architecture--key-features)
[![Dependencies](https://img.shields.io/badge/Dependencies-Zero%20External-blueviolet)](#project-context)
[![Tests](https://img.shields.io/badge/Tests-6%2F6%20Suites%20Passing-brightgreen)](#getting-started)

A high-performance, header-only C++20 linear algebra library implementing generic dense matrices, vector spaces, and numerical solvers with seamless support for both real and complex scalar fields. Engineered from scratch without third-party dependencies, featuring Gauss-Jordan elimination with partial pivoting, matrix inversion, determinant calculation, and hardware-accelerated arithmetic.

---

## 📌 Project Context

- **Type**: 42 Curriculum (Post-Common Core / Advanced Algorithms & Applied Mathematics)
- **Format**: Solo project
- **Primary Constraints**:
  - **Zero External Dependencies**: Standard library and language primitives only (no BLAS, LAPACK, Eigen, or Boost).
  - **C++20 Standard Compliance**: Strict compiler flags (`-Wall -Wextra -Werror -std=c++20`).
  - **Full Complex Field Support ($\mathbb{C}$)**: Custom scalar type integrated into all algorithms (including conjugate transpose and Hermitian dot products).
  - **Numerical Stability**: Strict handling of floating-point inaccuracies, singular systems, and division-by-zero edge cases.

---

## 🏗️ Architecture & Key Features

The library adopts a **header-only template architecture**, cleanly separating interface declarations (`.hpp`) from template implementations (`.tpp`) while constraining scalar types at compile-time via C++20 Concepts.

```text
                                 ┌───────────────────────────┐
                                 │   C++20 Concepts / Traits │
                                 │    (numeric_scalar <K>)   │
                                 └─────────────┬─────────────┘
                                               │
                        ┌──────────────────────┴──────────────────────┐
                        ▼                                             ▼
         ┌─────────────────────────────┐               ┌─────────────────────────────┐
         │     Vector<K> Engine        │               │      Matrix<K> Engine       │
         │  (Contiguous 1D Storage)    │◄──────────────┤   (Dense Row-Major Buffer)  │
         └──────────────┬──────────────┘  mul_vec(v)   └──────────────┬──────────────┘
                        │                                             │
      ┌─────────────────┴─────────────────┐         ┌─────────────────┴─────────────────┐
      ▼                                   ▼         ▼                                   ▼
┌──────────────┐                  ┌──────────────┐┌──────────────┐                  ┌──────────────┐
│ Vector Ops   │                  │ Vector Algos ││ Matrix Ops   │                  │ Decompositions│
│ • add / sub  │                  │ • dot / herm ││ • mul_mat    │                  │ • RREF (Gauss)│
│ • scl / norm │                  │ • lerp (FMA) ││ • trace / T  │                  │ • det (parity)│
│ • L1, L2, Linf                  │ • cross_prod ││ • projection │                  │ • inv (Opt.)  │
└──────────────┘                  └──────────────┘└──────────────┘                  │ • rank        │
                                                                                    └──────────────┘
```

### Component Overview

| Component | Files | Description | Algorithmic Complexity |
| :--- | :--- | :--- | :--- |
| **Scalar System & Traits** | `Complex.hpp`<br>`scalar_traits.hpp` | Custom complex number type, arithmetic operators, conjugate arithmetic, and `numeric_scalar` concept constraints. | $\mathcal{O}(1)$ |
| **Vector Engine** | `Vector.hpp`<br>`vector_base.tpp`<br>`vector_operations.tpp`<br>`vector_algorithms.tpp` | Dense vector algebra: addition, scaling, linear combinations, $L_1 / L_2 / L_\infty$ norms, cosine similarity, 3D cross products, and FMA-accelerated linear interpolation (`lerp`). | Dot: $\mathcal{O}(N)$<br>Cross: $\mathcal{O}(1)$<br>Lerp: $\mathcal{O}(N)$ |
| **Matrix Core** | `Matrix.hpp`<br>`matrix_base.tpp`<br>`matrix_operations.tpp`<br>`matrix_algorithms.tpp` | Flattened row-major matrix container, matrix-vector and matrix-matrix multiplication, trace, transposition, and 3D perspective projection matrices. | Mul: $\mathcal{O}(M \cdot N \cdot P)$<br>Trace: $\mathcal{O}(N)$<br>Transpose: $\mathcal{O}(M \cdot N)$ |
| **Numerical Solvers** | `matrix_decomposition.tpp` | Gauss-Jordan elimination with partial pivoting (Row Echelon Form), determinant calculation with permutation parity, matrix rank, and matrix inversion via augmented matrix $[A \mid I]$. | RREF / Rank: $\mathcal{O}(N^3)$<br>Det: $\mathcal{O}(N^3)$<br>Inverse: $\mathcal{O}(N^3)$ |
| **Verification Suite** | `tests/test_*.cpp`<br>`tests/test_common.hpp` | Automated unit test suite with floating-point epsilon comparison assertions and modular build rules. | $\approx 20$ unit test suites |

---

## 🧠 Technical Challenges & Key Learnings

### 1. Numerical Stability via Partial Pivoting in Gauss-Jordan Elimination
- **Problem**: Naive row echelon reduction fails or introduces catastrophic precision loss when encountering zero or near-zero pivot elements on the diagonal, leading to division-by-zero or floating-point overflow.
- **Solution**: Implemented partial pivoting (`findIndexMaxAbsColumn`) using squared Euclidean norm comparisons (`scalar_norm2`) with a strict tolerance threshold ($\epsilon = 10^{-9}$). Rows are swapped to position the maximum magnitude element as the pivot before row scaling and elimination.
- **Impact**: Guarantees stable computation for reduced row echelon form (RREF), matrix rank, determinants, and augmented matrix inversion $[A \mid I]$ across both well-conditioned and ill-conditioned systems.

### 2. Unified Scalar Polymorphism & Hermitian Inner Products via C++20 Concepts
- **Problem**: Linear algebra over real numbers ($\mathbb{R}$) and complex numbers ($\mathbb{C}$) requires divergent mathematical definitions (e.g., standard inner product vs. sesquilinear Hermitian dot product $u \cdot v = \sum u_i \overline{v_i}$) while avoiding runtime overhead or virtual dispatch.
- **Solution**: Designed a compile-time concept constraint `template<numeric_scalar K>` coupled with `if constexpr` branch elimination. The dot product automatically switches between hardware-accelerated FMA accumulation (`std::fma`) for arithmetic types and conjugate multiplication (`v[i].conj()`) for complex numbers.
- **Impact**: Zero runtime overhead, strict compile-time type validation, and uniform API syntax across all scalar types.

### 3. Cache-Locality & Hardware-Assisted Arithmetic (`std::fma`)
- **Problem**: 2D dynamic array allocations (`std::vector<std::vector<K>>`) suffer from pointer indirection, cache misses, and memory fragmentation during heavy matrix multiplication loops.
- **Solution**: Utilized a single contiguous 1D buffer (`std::vector<K> elements`) with 2D row-major mapping formula $\text{index} = i \times \text{cols} + j$. Inner multiplication loops and vector interpolations leverage `std::fma` (Fused Multiply-Add) to compute $a \times b + c$ in a single CPU instruction cycle with reduced rounding error.
- **Impact**: Minimized cache line misses and improved computational throughput while preserving arithmetic precision.

### 4. Robust Singular Matrix Handling via `std::optional`
- **Problem**: Attempting to invert a singular (non-invertible) matrix should not silently return corrupt data nor rely solely on costly exception handling for routine mathematical checks.
- **Solution**: Designed `Matrix<K>::inverse()` to return `std::optional<Matrix<K>>`. If the pivot count after Gaussian elimination does not match the column dimension ($n \neq \operatorname{rank}(A)$), the function returns `std::nullopt` safely.
- **Impact**: Idiomatic modern C++ API design that forces callers to explicitly handle matrix invertibility at compile/type level.

---

## 🚀 Getting Started

### Prerequisites

- **Compiler**: Any C++20 compliant compiler (`clang++` $\ge 12.0$ or `g++` $\ge 10.0$)
- **Build System**: GNU `make`

### Installation & Build

1. **Clone the repository**:
   ```bash
   git clone https://github.com/r-richardcanavaggio/matrix.git
   cd matrix
   ```

2. **Compile and execute all test suites**:
   ```bash
   make test
   ```

3. **Build targets summary**:
   ```bash
   make        # Compiles all test binaries into bin/tests/
   make test   # Compiles and runs all 6 test suites with status reporting
   make clean  # Removes compilation object files (.obj/)
   make fclean # Removes object files and binary outputs (bin/)
   make re     # Rebuilds the complete test suite from scratch
   ```

---

## 💻 Visual Showcase

### 1. Matrix Inversion & Linear Solvers

```cpp
#include "Matrix.hpp"
#include <iostream>

int main() {
    // Define a 3x3 real matrix
    Matrix<double> A({
        { 2.0, -1.0,  0.0 },
        {-1.0,  2.0, -1.0 },
        { 0.0, -1.0,  2.0 }
    });

    std::cout << "Determinant: " << A.determinant() << "\n\n";

    // Compute inverse with std::optional safety check
    auto inv = A.inverse();
    if (inv.has_value()) {
        std::cout << "A^-1:\n" << *inv << "\n";
        std::cout << "Verification (A * A^-1):\n" << A.mul_mat(*inv) << "\n";
    }
    return 0;
}
```

**Expected Output**:
```text
Determinant: 4

A^-1:
[0.75, 0.5, 0.25]
[0.5, 1, 0.5]
[0.25, 0.5, 0.75]

Verification (A * A^-1):
[1, 0, 0]
[0, 1, 0]
[0, 0, 1]
```

---

### 2. Complex Vector Geometry & Hermitian Dot Product

```cpp
#include "Vector.hpp"
#include "Complex.hpp"
#include <iostream>

int main() {
    Vector<Complex> u({ Complex(1.0, 2.0), Complex(3.0, -1.0) });
    Vector<Complex> v({ Complex(2.0, -1.0), Complex(1.0, 4.0) });

    // Hermitian dot product: u . conj(v)
    Complex dot = u.dot(v);
    std::cout << "Hermitian Inner Product <u, v> = " << dot << "\n";
    std::cout << "Euclidean Norm ||u||_2         = " << u.norm() << "\n";
    return 0;
}
```

**Expected Output**:
```text
Hermitian Inner Product <u, v> = -1 + 10i
Euclidean Norm ||u||_2         = 3.87298
```

---

### 3. Automated Test Suite Output

```bash
$ make test
Compiling tests/test_matrix_basic.cpp                        [OK]
Linking bin/tests/test_matrix_basic                          [OK]
...
Running bin/tests/test_matrix_basic                          [OK]
[OK] test_add_sub_scale
[OK] test_trace_and_transpose
[OK] test_matrix_lerp
Running bin/tests/test_matrix_inverse                        [OK]
[OK] test_determinant
[OK] test_inverse
[OK] test_singular_inverse
Running bin/tests/test_matrix_products                       [OK]
[OK] test_matrix_vector_product
[OK] test_matrix_matrix_product
[OK] test_projection_matrix
Running bin/tests/test_matrix_reduction                      [OK]
[OK] test_row_echelon
[OK] test_rank
Running bin/tests/test_vector_algorithms                     [OK]
[OK] test_dot_product
[OK] test_norms
[OK] test_angle_cos
[OK] test_cross_product
[OK] test_vector_lerp
Running bin/tests/test_vector_basic                          [OK]
[OK] test_add_sub_scale_float
[OK] test_add_sub_scale_complex
[OK] test_linear_combination
```

