/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:51:26 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 11:41:02 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Determinant.tpp"

int	main( void )
{
	try
	{
		Matrix<double>	u{{8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.}};
		Matrix<double>	u1{{8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.}};
		Matrix<double>	u2{{2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.}};
		Matrix<Complex>	u3{
			{{2, 1}, {1, 2}, {1, 1}},
			{{1, 3}, {-1, -2}, {-2, 1}},
			{{-2, 1}, {0, 2}, {0, 0}}
		};

		std::cout << u2 << std::endl << u2.determinant() << std::endl;
		std::cout << u << std::endl << u.determinant() << std::endl;
		std::cout << u1 << std::endl << u1.determinant() << std::endl;
		std::cout << u3 << std::endl << u3.determinant() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}