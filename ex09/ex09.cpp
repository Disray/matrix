/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:14:06 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 15:34:21 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Matrix.hpp"

int	main( void )
{
	Matrix<double>	u{{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
	std::cout << u << std::endl << u.transpose() << std::endl;
	Matrix<double>	u1{{1., 2., 3.}, {4., 5., 6.}};
	std::cout << u1 << std::endl << u1.transpose();
	Matrix<Complex>	A4({ {{1, 2}, {-1, -2}, {0, 3}},
						{{2, -1}, {2, 1}, {1, -4}},
						{{-5, 1}, {1.5, 0}, {-3.2, 1}} });
	std::cout << A4 << std::endl << A4.transpose();
	return 0;
}