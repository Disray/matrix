/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:37:18 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 15:27:36 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"

int	main( void )
{
    std::cout << std::fixed << std::setprecision(9);

	try 
	{
		Vector<double> a1({0., 0., 1.}), b1({1., 0., 0.});
		std::cout << cross_product(a1, b1) << std::endl;
	
		Vector<double> a2({1., 2., 3.}), b2({4., 5., 6.});
		std::cout << cross_product(a2, b2) << std::endl;
	
		Vector<double> a3({4., 2., -3.}), b3({-2., -5., 16.});
		std::cout << cross_product(a3, b3) << std::endl;

		Vector<Complex>	u({
			{1, 2}, {-1, 1}, {3, 3}
		});
		Vector<Complex>	v({
			{2, 1}, {3, -4}, {-2, -5}
		});
		std::cout << cross_product(u, v) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}