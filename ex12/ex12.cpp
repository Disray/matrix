/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:57:17 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/06 18:03:17 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inverse.tpp"

template<typename K>
void testInverse(const char* name, const Matrix<K>& M)
{
    auto inv = M.inverse();
    std::cout << name << ":\n";
    if (inv)
    {
        std::cout << *inv << "\n";
        // Optional quick check: M * inv ≈ I
        auto prod = M.mul_mat(*inv);
        std::cout << "M * inv:\n" << prod << "\n";
    }
    else
        std::cout << "Error: " << inv.error() << "\n";
    std::cout << "----\n";
}

int main()
{
    std::cout << std::fixed << std::setprecision(6);

    // Original examples
    Matrix<double> diag3 = {
        {2.0, 0.0, 0.0},
        {0.0, 2.0, 0.0},
        {0.0, 0.0, 2.0}
    };
    Matrix<double> m1 = {
        {8., 5., -2.},
        {4., 7., 20.},
        {7., 6., 1.}
    };

    // Identity 2x2
    Matrix<double> I2 = {
        {1., 0.},
        {0., 1.}
    };

    // Diagonal 2x2
    Matrix<double> D2 = {
        {2., 0.},
        {0., 3.}
    };

    // Shear 2x2
    Matrix<double> Shear = {
        {1., 2.},
        {0., 1.}
    };

    // Rotation 90° (orthogonal)
    Matrix<double> Rot = {
        {0., -1.},
        {1.,  0.}
    };

    // Integer-invertible 3x3 (det=1)
    Matrix<double> Int3 = {
        {1., 2., 3.},
        {0., 1., 4.},
        {5., 6., 0.}
    };

    // Permutation 3x3
    Matrix<double> Perm3 = {
        {0., 1., 0.},
        {0., 0., 1.},
        {1., 0., 0.}
    };

    // Singular (det=0)
    Matrix<double> Sing2 = {
        {1., 2.},
        {2., 4.}
    };

    testInverse("diag3", diag3);
    testInverse("m1", m1);
    testInverse("I2", I2);
    testInverse("D2", D2);
    testInverse("Shear", Shear);
    testInverse("Rot", Rot);
    testInverse("Int3", Int3);
    testInverse("Perm3", Perm3);
    testInverse("Sing2 (should fail)", Sing2);

    return 0;
}