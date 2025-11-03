/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:47:57 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/03 14:38:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Multiply.tpp"

int main( void )
{
    std::cout << std::fixed << std::setprecision(9);

    Matrix<double> u1{{ {1., 0.}, {0., 1.} }};
    Vector<double> v1{ {4., 2.} };
    std::cout << u1.mul_vec(v1) << std::endl; // [4.] [2.]

    Matrix<double> u2{{ {2., 0.}, {0., 2.} }};
    Vector<double> v2{ {4., 2.} };
    std::cout << u2.mul_vec(v2) << std::endl; // [8.] [4.]

    Matrix<double> u3{{ {2., -2.}, {-2., 2.} }};
    Vector<double> v3{ {4., 2.} };
    std::cout << u3.mul_vec(v3) << std::endl; // [4.] [-4.]
	
    Matrix<double> u4{{ {3., -5.},
						{6., 8.} }};
    Matrix<double> v4{{ {2., 1.}, 
						{4., 2.} }};

	std::cout << u4.mul_mat(v4) << std::endl;


    Matrix<double> A3{{ {1., 2., 3.},
                        {4., 5., 6.},
                        {7., 8., 9.} }};
    Matrix<double> B3{{ {9., 8., 7.},
                        {6., 5., 4.},
                        {3., 2., 1.} }};
    std::cout << "A3 * B3 =\n" << A3.mul_mat(B3) << std::endl;
    return 0;
}