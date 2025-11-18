/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:28:32 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/15 19:04:24 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinearCombination.tpp"

int	main( void )
{
	Vector e1({1., 0., 0.});
	Vector e2({0., 1., 0.});
	Vector e3({0., 0., 1.});

	Vector v1({1., 2., 3.});
	Vector v2({0., 10., -100.});

	Vector<Complex> u1{{1., 2.}, {0., 1.}, {-2., 0.}};
	Vector<Complex> u2{{0., 1.}, {-1., -2.}, {-1., -4.}};
	Vector<Complex> u3{{5., 2.}, {3., -1.}, {2., 1.}};

	std::vector<Vector<double>> u = {e1, e2, e3};
	std::vector<double>			coefs = {10., -2., 0.5};

	std::cout << linear_combination(u, coefs) << std::endl;
	std::cout << linear_combination({v1, v2}, {10., -2.}) << std::endl;
	std::cout << linear_combination({u1, u2, u3}, {{1., 1.}, {0., -1.}, {2., 3.}}) << std::endl;
}