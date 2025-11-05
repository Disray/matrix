/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:51:26 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/05 16:45:46 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Determinant.tpp"

int	main( void )
{
	Matrix<double>	u{{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}};
	Matrix<double>	u1{{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}};
	Matrix<double>	u2{{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}};

	std::cout << u2 << std::endl << u2.determinant() << std::endl;
	std::cout << u << std::endl << u.determinant() << std::endl;
	std::cout << u1 << std::endl << u1.determinant() << std::endl;
	return (0);
}