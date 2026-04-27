# matrix

![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![Build System](https://img.shields.io/badge/build-make-informational.svg)
![Tests](https://img.shields.io/badge/tests-binary%20suite-success.svg)

A small C++20 linear algebra library focused on dense vectors and matrices, with support for real and complex scalars.

## Table of Contents

- [What This Project Does](#what-this-project-does)
- [Why This Project Is Useful](#why-this-project-is-useful)
- [Project Layout](#project-layout)
- [Getting Started](#getting-started)
- [Usage Examples](#usage-examples)
- [Where to Get Help](#where-to-get-help)
- [Maintainers and Contributing](#maintainers-and-contributing)

## What This Project Does

This repository provides:

- A generic `Vector<K>` template for core vector algebra
- A generic `Matrix<K>` template for dense row-major matrix algebra
- A lightweight `Complex` scalar type compatible with vector/matrix operations
- Linear algebra algorithms such as dot products, norms, interpolation, row reduction, determinant, inverse, and rank

The code is template-based and distributed through headers in `include/` and `include/details/`.

## Why This Project Is Useful

- Practical foundation for learning and experimenting with linear algebra in C++
- Unified API for arithmetic scalars and custom complex numbers
- Includes both basic operations and higher-level decomposition/reduction routines
- Comes with executable test programs that demonstrate expected behavior and edge cases

## Project Layout

```text
include/
  Vector.hpp
  Matrix.hpp
  Complex.hpp
  details/
tests/
  test_vector_basic.cpp
  test_vector_algorithms.cpp
  test_matrix_basic.cpp
  test_matrix_products.cpp
  test_matrix_reduction.cpp
  test_matrix_inverse.cpp
Makefile
```

## Getting Started

### Prerequisites

- A C++20 compiler (`c++`)
- `make`

### Build all test binaries

```bash
make
```

### Run the full test suite

```bash
make test
```

### Clean artifacts

```bash
make clean     # remove object files
make fclean    # remove objects and binaries
```

## Usage Examples

### Vector operations

```cpp
#include "Vector.hpp"
#include <iostream>

int main() {
    Vector<double> u{1.0, 2.0, 3.0};
    Vector<double> v{4.0, 5.0, 6.0};

    std::cout << "dot = " << u.dot(v) << "\n";
    std::cout << "norm(u) = " << u.norm() << "\n";

    auto cross = cross_product(u, v);
    std::cout << "cross = " << cross << "\n";
}
```

### Matrix operations

```cpp
#include "Matrix.hpp"
#include <iostream>

int main() {
    Matrix<double> a{{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double> b{{2.0, 0.0}, {1.0, 2.0}};

    auto c = a.mul_mat(b);
    std::cout << "A * B =\n" << c << "\n";
    std::cout << "det(A) = " << a.determinant() << "\n";

    auto inv = a.inverse();
    if (inv.has_value()) {
        std::cout << "A^-1 =\n" << *inv << "\n";
    }
}
```

### Compile a standalone example

```bash
c++ -std=c++20 -Iinclude your_example.cpp -o your_example
./your_example
```

## Where to Get Help

- Open an issue: https://github.com/r-richardcanavaggio/matrix/issues
- Inspect runnable examples in `tests/` for API usage patterns
- Use `make help` to list available Make targets

## Maintainers and Contributing

- Maintainer: [r-richardcanavaggio](https://github.com/r-richardcanavaggio)

Contributions are welcome.

1. Fork the repository and create a feature branch.
2. Add or update tests under `tests/` for your changes.
3. Ensure `make test` passes.
4. Open a pull request with a clear description of the change.
