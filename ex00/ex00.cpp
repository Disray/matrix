/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:18:21 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:40:00 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VAddSubScl.tpp"
#include "MAddSubScl.tpp"

int main( void )
{
	Vector<float>	u{2.5f, 3.5f};
	Vector<float>	v = u;
	Matrix<float>	m{{1.0f, 2.0f}, {3.0f, 4.0f}};
	Matrix<float>	m1{{7.0f, 4.0f}, {-2.0f, 2.0f}};

	std::cout << "Initial vector u: " << std::endl;
	std::cout << u;
	std::cout << "-------" << std::endl;

	std::cout << "Adding vector v to vector u:" << std::endl;
	u.add(v);
	std::cout << u;
	std::cout << "-------" << std::endl;

	std::cout << "Scaling vector u by 2:" << std::endl;
	u.scl(2);
	std::cout << u;
	std::cout << "-------" << std::endl;

	std::cout << "Scaling vector u by 3:" << std::endl;
	u.scl(3);
	std::cout << u;
	std::cout << "-------" << std::endl;

	std::cout << "Initial matrix m: " << std::endl;
	std::cout << m;
	std::cout << "-------" << std::endl;

	std::cout << "Adding matrix m1 to matrix m:" << std::endl;
	m.add(m1);
	std::cout << m;
	std::cout << "-------" << std::endl;

	std::cout << "Scaling matrix m by 2.0:" << std::endl;
	m.scl(2.0f);
	std::cout << m;
	return (0);
}