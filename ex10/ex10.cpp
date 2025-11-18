/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:31:11 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/18 19:28:13 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RowEchelon.tpp"

int	main( void )
{
	try
	{
		Matrix<double>	u{	{2., 1., -1.},
							{-3., -1., 2.},
							{-2., 1., 2.}	};
		Matrix<double>	u1{	{8., 5., -2., 4., 28.},
							{4., 2.5, 20., 4., -4.},
							{8., 5., 1., 4., 17.}	};
		Matrix<double>	u2{	{1., 2.}, {2., 4.}	};
		Matrix<double>	u3{	{1., 2.}, {3., 4.}	};
		Matrix<Complex>	z{	{{1, 2}, {2, 1}, {1, 2}},
							{{2, 1}, {1, 3}, {3, 1}},
							{{-3, -1}, {1, -2}, {0, 4}}	};
		std::cout << u << std::endl << u.row_echelon() << "-------" << std::endl;
		std::cout << u3 << std::endl << u3.row_echelon() << "-------" << std::endl;
		std::cout << u2 << std::endl << u2.row_echelon() << "-------" << std::endl;
		std::cout << u1 << std::endl << u1.row_echelon() << "-------" << std::endl;
		std::cout << z << std::endl << z.row_echelon() << "--------" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}