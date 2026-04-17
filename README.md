# Matrix

`Matrix` est une bibliothèque C++ `header-only` de calcul matriciel et vectoriel. Elle fournit deux types templates, `Matrix` et `Vector`, ainsi qu'un petit ensemble d'algorithmes usuels de l'algèbre linéaire: interpolation linéaire, produit scalaire, produit vectoriel, multiplication matrice-vecteur, multiplication matrice-matrice, trace, transposée, forme échelonnée, déterminant, inverse et rang.

## Fonctionnalités

- Matrices et vecteurs denses templatisés
- Support des types arithmétiques standards
- Support du type `Complex` fourni par la bibliothèque
- Bibliothèque `header-only`, sans phase de linkage dédiée
- Jeux de tests compilables et exécutables via `make test`

## Arborescence utile

```text
.
├── include/
│   ├── Matrix.hpp
│   ├── Vector.hpp
│   └── Complex.hpp
├── tests/
└── Makefile
```

## Prérequis

- Compilateur compatible C++20
- `make`

## Utilisation

Exemple minimal:

```cpp
#include "Matrix.hpp"

int main()
{
	Matrix<double> a{{1.0, 2.0}, {3.0, 4.0}};
	Vector<double> x{5.0, 6.0};
	Vector<double> y = a.mul_vec(x);
	return (y.getSize() == 2 ? 0 : 1);
}
```

Compilation manuelle:

```sh
c++ -std=c++20 -Wall -Wextra -Werror -Iinclude example.cpp -o example
```

## API principale

`Vector`

- `add`, `sub`, `scl`
- `dot`
- `norm_1`, `norm`, `norm_inf`

Algorithmes associés:

- `linear_combination`
- `lerp`
- `angle_cos`
- `cross_product`

`Matrix`

- `add`, `sub`, `scl`
- `mul_vec`, `mul_mat`
- `trace`
- `transpose`
- `row_echelon`
- `determinant`
- `inverse`
- `rank`

Algorithmes associés:

- `lerp`
- `projection`

## Makefile

- `make` ou `make all` compile tous les tests
- `make test` compile puis exécute tous les tests
- `make clean` supprime les fichiers objets
- `make fclean` supprime les fichiers objets et les binaires
- `make re` reconstruit entièrement le projet

## Tests

Les tests sont regroupés dans le dossier `tests/`. Chaque exécutable de test inclut directement les en-têtes publics de la bibliothèque et vérifie un sous-ensemble des opérations fournies.
