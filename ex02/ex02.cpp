/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:28:32 by rrichard          #+#    #+#             */
/*   Updated: 2025/10/31 16:33:04 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_interpolation.hpp"

int	main( void )
{
	std::cout << lerp(0., 1., 0.) << std::endl;
	std::cout << lerp(0., 1., 1.) << std::endl;
	std::cout << lerp(0., 1., 0.5) << std::endl;
	std::cout << lerp(21., 42., 0.3) << std::endl;

	std::cout << lerp(Vector<double>({2., 1.}), Vector<double>({4., 2.}), 0.3);
	std::cout << lerp(Matrix<double>({{2., 1.}, {3., 4.}}), Matrix<double>({{20., 10.}, {30., 40.}}), 0.5);
	return (0);
}