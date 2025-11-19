/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:37:18 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 09:49:42 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"

int	main( void )
{
	std::cout << std::fixed << std::setprecision(9);
	Vector<float>	u({-1.0f, -2.0f});
	std::cout << u.norm_1() << std::endl << u.norm() << std::endl;

	Vector<double>	u1({-1., -2.});
	std::cout << u1.norm_1() << std::endl << u1.norm() << std::endl << u1.norm_inf() << std::endl;

	Vector<Complex>	c({
		{0., 1.}, {3., 1.}
	});
	std::cout << c.norm_1() << std::endl << c.norm() << std::endl << c.norm_inf() << std::endl;
	return (0);
}