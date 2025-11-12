/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearInterpolation.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:50:36 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 14:03:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "../ex00/Vector.hpp"
# include "../Matrix.hpp"

template<is_arithmetic K>
K lerp( const K& a, const K& b, const K& t)
{
	return (a + (b - a) * t);
}

template<is_arithmetic K>
Vector<K>	lerp( const Vector<K>& u, const Vector<K>& v, const K& t )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Empty vector");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Vectors must have the same size");

	Vector<K>	result(u.getSize());
	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
	
}

template<is_arithmetic K>
Matrix<K>	lerp( const Matrix<K>& u, const Matrix<K>& v, const K& t )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Empty vector");
	if (!u.hasSameDim(v))
		throw std::runtime_error("Matrices must have the same dimensions");

	Matrix<K>	result(u.getCols(), u.getRows());
	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}