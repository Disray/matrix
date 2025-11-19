/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearInterpolation.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:50:36 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 10:21:16 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"
#include "../Matrix.hpp"

template<is_arithmetic K>
K	lerp( K a, K b, double t )
{
	if constexpr (std::is_arithmetic_v<K>)
		return (std::fma(b - a, static_cast<K>(t), a));
	else
		return (a + (b - a) * static_cast<K>(t));
}

template<is_arithmetic K>
Vector<K>	lerp( const Vector<K>& u, const Vector<K>& v, double t )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input vectors are empty");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for linear interpolation");

	Vector<K>	result(u.getSize());

	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}

template<is_arithmetic K>
Matrix<K>	lerp( const Matrix<K>& u, const Matrix<K>& v, double t )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input matrices are empty for linear interpolation");
	if (!u.hasSameDim(v))
		throw std::runtime_error("Error: input matrices must have the same dimensions for linear interpolation");

	Matrix<K>	result(u.getCols(), u.getRows());

	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}