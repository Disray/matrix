/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:18:21 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 15:15:27 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main( void )
{
	Vector<float>	u{2.5f, 3.5f};
	Vector<float>	v = u;
	Matrix<float>	m{{1.0f, 2.0f}, {3.0f, 4.0f}};
	Matrix<float>	m1{{7.0f, 4.0f}, {-2.0f, 2.0f}};
	Complex			z1(10., 2.);
	Complex			z2(3., 4.);
	Vector<Complex>	c{z1, z2};
	Vector<Complex>	c2{{0., -1.}, {2., -5.}};

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
	std::cout << "-------" << std::endl;

	std::cout << "Adding complex vectors" << std::endl;
	c.add(c2);
	std::cout << c;
	std::cout << "-------" << std::endl;

	std::cout << "Sub complex vectors" << std::endl;
	std::cout << c2 << std::endl;
	c2.sub(c);
	std::cout << c2;
	std::cout << "-------" << std::endl;

	std::cout << "Scaling vector c by z = 4 - 3i:" << std::endl;
	std::cout << c << std::endl;
	c.scl({4., -3});
	std::cout << c;
	std::cout << "-------" << std::endl;
	return (0);
}