/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:37:18 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/17 10:14:43 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"

int	main( void )
{
	Vector<float>	u({-1.0f, -2.0f});
	std::cout << std::fixed << u.norm_1() << std::endl << u.norm() << std::endl;

	Vector<double>	u1({-1., -2.});
	std::cout << std::fixed << std::setprecision(9) << u1.norm_1() << std::endl << u1.norm() << std::endl << u1.norm_inf() << std::endl;

	Vector<Complex>	c({
		{0., 1.}, {3., 1.}
	});
	std::cout << "Norm of complex vector:\n[0 + 1i]\n[3 + 1i]\n" << c.norm_1() << std::endl << c.norm() << std::endl << c.norm_inf() << std::endl;
	return (0);
}