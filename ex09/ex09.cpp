/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:14:06 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/04 10:31:09 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Transpose.tpp"

int	main( void )
{
	Matrix<double>	u{{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
	std::cout << u << std::endl << u.transpose() << std::endl;
	Matrix<double>	u1{{1., 2., 3.}, {4., 5., 6.}};
	std::cout << u1 << std::endl << u1.transpose();
	return 0;
}