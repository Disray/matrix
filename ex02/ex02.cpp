/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:28:32 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/03 16:47:16 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector.hpp"
#include "../Matrix.hpp"

int main( void )
{
	std::cout << std::fixed << std::setprecision(4);

	std::cout << "SCALAR\n\n";

	std::cout << "[float]\n";
	std::cout << "  u = 0\n"
			  << "  v = 1\n"
			  << "  t = 0.5\n"
			  << "  lerp(u, v, t) = " << lerp(0.f, 1.f, 0.5f) << "\n\n";

	Complex ca({1.0, 2.0}), cb({3.0, -1.0});
	std::cout << "[complex]\n";
	std::cout << "  u = 1 + 2i\n"
			  << "  v = 3 - 1i\n"
			  << "  t = 0.25\n"
			  << "  lerp(u, v, t) = " << lerp(ca, cb, 0.25f) << "\n\n";

	std::cout << "VECTOR LERP\n\n";

	std::cout << "[float]\n";
	Vector vfa({ 2.f, 1.f });
	Vector vfb({ 4.f, 2.f });
	std::cout << "u =\n" << vfa
			  << "v =\n" << vfb
			  << "t = 0.3\n"
			  << "lerp(u, v, t) =\n" << lerp(vfa, vfb, 0.3f) << "\n\n";

	std::cout << "[complex]\n";
	Vector<Complex> vu1({
		{ 3., 1. },
		{ 4., 2. }
	});
	Vector<Complex> vu2({
		{ 1., 2. },
		{ -1., -2. }
	});
	std::cout << "u =\n" << vu1
			  << "v =\n" << vu2
			  << "t = 0.5\n"
			  << "lerp(u, v, t) =\n" << lerp(vu1, vu2, 0.5f) << "\n\n";

	std::cout << "MATRIX LERP\n\n";

	std::cout << "[float]\n";
	Matrix mfa({
		{ 2.f, 1.f },
		{ 3.f, 4.f }
	});
	Matrix mfb({
		{ 20.f, 10.f },
		{ 30.f, 40.f }
	});
	std::cout << "u =\n" << mfa
			  << "v =\n" << mfb
			  << "t = 0.5\n"
			  << "lerp(u, v, t) =\n" << lerp(mfa, mfb, 0.5f) << "\n\n";

	std::cout << "[complex]\n";
	Matrix<Complex> mcA({
		{ {1., 1.}, {2., -1.} },
		{ {0., 2.}, {3.,  0.} }
	});
	Matrix<Complex> mcB({
		{ {3., -2.}, {0., 1.} },
		{ {1.,  0.}, {-1., 4.} }
	});
	std::cout << "u =\n" << mcA
			  << "v =\n" << mcB
			  << "t = 0.25\n"
			  << "lerp(u, v, t) =\n" << lerp(mcA, mcB, 0.25f) << "\n";

	return (0);
}