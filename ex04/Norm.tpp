/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:44:05 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/18 19:01:21 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"

double	complex_absolute( const Complex& z )
{
	double	real_sq = z.Re * z.Re;
	double	imag_sq = z.Im * z.Im;

	return (std::pow(real_sq + imag_sq, 0.5));
}

/**
 * @brief Norme L1 (somme des valeurs absolues).
 * Réels/entiers: Σ |x_i|. Complexes: Σ |z_i| (module de chaque composante).
 * @return double (toujours réel, ≥ 0).
 * Complexité: O(n).
 */
template<is_arithmetic K>
double	Vector<K>::norm_1() const
{
	double	result = 0.;

	if constexpr (std::is_arithmetic_v<K>)
	{
		for (size_t i = 0; i < this->getSize(); i++)
			result += this->fields[i] < K(0) ? -this->fields[i] : this->fields[i];
	}
	else
	{
		for (size_t i = 0; i < this->getSize(); i++)
			result += complex_absolute(this->fields[i]);
	}
	return (result);
}

/**
 * @brief Norme Euclidienne (L2).
 * Réels/entiers: sqrt(Σ x_i^2). Complexes: sqrt(Σ |z_i|^2).
 * @return double (toujours réel, ≥ 0).
 * Complexité: O(n).
 */
template<is_arithmetic K>
double	Vector<K>::norm() const
{
	double	result = 0;

	if constexpr (std::is_arithmetic_v<K>)
	{
		for (size_t i = 0; i < this->getSize(); i++)
			result = std::fma(this->fields[i], this->fields[i], result);
		result = std::pow(result, 0.5);
	}
	else
	{
		for (size_t i = 0; i < this->getSize(); i++)
			result += this->fields[i].real() * this->fields[i].real()
					+ this->fields[i].imag() * this->fields[i].imag();
		result = std::pow(result, 0.5);
	}
	return (result);
}

/**
 * @brief Norme infinie (max des valeurs absolues).
 * Réels/entiers: max_i |x_i|. Complexes: max_i |z_i|.
 * @return double (toujours réel, ≥ 0).
 * Complexité: O(n).
 */
template<is_arithmetic K>
double	Vector<K>::norm_inf() const
{
	double result = 0;

	if constexpr (std::is_arithmetic_v<K>)
	{
		for (size_t i = 0; i < this->getSize(); i++)
			result = std::max(result, this->fields[i] < 0 ? -this->fields[i] : this->fields[i]);
	}
	else
	{
		for (size_t i = 0; i < this->getSize(); i++)
			result = std::max(result, complex_absolute(this->fields[i]));
	}
	return (result);
}
