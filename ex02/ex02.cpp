/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:28:32 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/15 19:04:24 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinearInterpolation.tpp"

int main( void )
{
	std::cout << "[Scalar int]    lerp(0, 10, 0.25f) = " << lerp(0, 10, 0.25f) << std::endl;
	std::cout << "[Scalar float]  lerp(0.f, 1.f, 0.5f) = " << lerp(0.f, 1.f, 0.5f) << std::endl;
	Complex ca{1.0, 2.0}, cb{3.0, -1.0};
	std::cout << "[Scalar complex] lerp((1+2i),(3-1i), 0.25f) = " << lerp(ca, cb, 0.25f) << std::endl << std::endl;

	std::cout << "[Vector int]" << std::endl;
	std::cout << lerp(Vector<int>({1, 3}), Vector<int>({5, 7}), 0.25f) << '\n';

	std::cout << "[Vector float]" << std::endl;
	std::cout << lerp(Vector<float>({2.f, 1.f}), Vector<float>({4.f, 2.f}), 0.3f) << '\n';

	std::cout << "[Vector complex]" << std::endl;
	Vector<Complex> vu1{{3., 1.}, {4., 2.}};
	Vector<Complex> vu2{{1., 2.}, {-1., -2.}};
	std::cout << lerp(vu1, vu2, 0.5f) << std::endl << std::endl;

	std::cout << "[Matrix int]" << std::endl;
	std::cout << lerp(
		Matrix<int>({{1, 2}, {3, 4}}),
		Matrix<int>({{5, 6}, {7, 8}}),
		0.5f) << std::endl;

	std::cout << "[Matrix float]" << std::endl;
	std::cout << lerp(
		Matrix<float>({{2.f, 1.f}, {3.f, 4.f}}),
		Matrix<float>({{20.f, 10.f}, {30.f, 40.f}}),
		0.5f) << std::endl;

	std::cout << "[Matrix complex]" << std::endl;
	Matrix<Complex> mcA({
		{ {1., 1.}, {2., -1.} },
		{ {0., 2.}, {3.,  0.} }
	});
	Matrix<Complex> mcB({
		{ {3., -2.}, {0., 1.} },
		{ {1.,  0.}, {-1., 4.} }
	});
	std::cout << lerp(mcA, mcB, 0.25f) << std::endl;

	return (0);
}