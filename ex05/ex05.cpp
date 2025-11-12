/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex05.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:37:18 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:12:26 by rrichard         ###   ########.fr       */
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
	return (0);
}