/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinearInterpolation.tpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:50:36 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/15 19:04:24 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"
#include "../Matrix.hpp"

/**
 * @brief Interpolation linéaire scalaire.
 * Calcule a + (b - a) * t pour t dans [0,1] (t peut être hors intervalle pour extrapoler).
 * @param a Valeur de départ.
 * @param b Valeur d'arrivée.
 * @param t Facteur (0 => a, 1 => b).
 * @return Valeur interpolée. Type: std::common_type_t<K, double>
 *         (ex: int -> double, float -> double, Complex -> Complex).
 */
template<is_arithmetic K>
auto	lerp( K a, K b, double t )
	-> std::common_type_t<K, double>
{
	using	promoted_t = std::common_type_t<K, double>;

	if constexpr (std::is_arithmetic_v<K>)
		return (std::fma(b - a, static_cast<promoted_t>(t), a));
	return (a + (b - a) * static_cast<promoted_t>(t));
}

/**
 * @brief Interpolation linéaire composante par composante entre deux vecteurs.
 * Préconditions: tailles égales, non vides. result[i] = lerp(u[i], v[i], t).
 * @return Vector interpolé. Type: Vector<std::common_type_t<K, double>>.
 */
template<is_arithmetic K>
auto	lerp( const Vector<K>& u, const Vector<K>& v, double t )
	-> Vector<std::common_type_t<K, double>>
{
	using	promoted_t = std::common_type_t<K, double>;

	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input vectors are empty");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for linear interpolation");

	Vector<promoted_t>	result(u.getSize());

	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}

/**
 * @brief Interpolation linéaire élément par élément entre deux matrices.
 * Préconditions: mêmes dimensions, non vides. result[k] = lerp(u[k], v[k], t) sur le stockage linéaire.
 * @return Matrix interpolée. Type: Matrix<std::common_type_t<K, double>>.
 */
template<is_arithmetic K>
auto	lerp( const Matrix<K>& u, const Matrix<K>& v, double t )
	-> Matrix<std::common_type_t<K, double>>
{
	using	promoted_t = std::common_type_t<K, double>;
	
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input matrices are empty for linear interpolation");
	if (!u.hasSameDim(v))
		throw std::runtime_error("Error: input matrices must have the same size for linear interpolation");

	Matrix<promoted_t>	result(u.getCols(), u.getRows());

	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}