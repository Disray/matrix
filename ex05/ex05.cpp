/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:37:18 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/15 19:04:24 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include "AngleCos.tpp"

int	main( void )
{
	std::cout << std::fixed << std::setprecision(9);

	Vector<double> u1({1., 0.}), v1({1., 0.});
    std::cout << angle_cos(u1, v1) << std::endl;

    Vector<double> u2({1., 0.}), v2({0., 1.});
    std::cout << angle_cos(u2, v2) << std::endl;

    Vector<double> u3({-1., 1.}), v3({1., -1.});
    std::cout << angle_cos(u3, v3) << std::endl;

    Vector<double> u4({2., 1.}), v4({4., 2.});
    std::cout << angle_cos(u4, v4) << std::endl;
	
	Vector<double>	u({1., 2., 3.}), v({4., 5., 6.});
	std::cout << angle_cos(u, v) << std::endl;

	Vector<Complex>	uz({{1., 2.}, {-2., -5}, {3., -4}});
	Vector<Complex>	vz({{4., 2.}, {5., -1.}, {-5., 0.}});
	std::cout << angle_cos(uz, vz) << std::endl;
	return (0);
}