/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_combination.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:45:01 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/03 14:43:04 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ex00/Vector.hpp"

template<is_arithmetic K>
Vector<K>	linear_combination( const std::vector<Vector<K>>& u, const std::vector<K>& coefs )
{
	if (u.empty())
		throw std::runtime_error("Input vector is empty");
	if (u.size() != coefs.size())
		throw std::runtime_error("Inconsistent array size for linear combination");

	size_t	expected_size = u[0].getSize();

	for (const auto& vec : u)
		if (vec.getSize() != expected_size)
			throw std::runtime_error("Vectors have different sizes");

	Vector<K>	result(expected_size);
	for (size_t i = 0; i < u.size(); i++)
		for (size_t j = 0; j < result.getSize(); j++)
			result[j] += coefs[i] * u[i][j];
	return (result);
}

template<is_arithmetic K>
Vector<K>	linear_combination( std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs )
{
	if (u.size() == 0)
		throw std::runtime_error("Input vector is empty");
	if (u.size() != coefs.size())
		throw std::runtime_error("Inconsistent array size for linear combination");

	auto	u_it = u.begin();
	size_t	expected_size = u_it->getSize();
	for (const auto& vec : u)
		if (vec.getSize() != expected_size)
			throw std::runtime_error("Vectors have different sizes");

	Vector<K>	result(expected_size);
	auto	coef_it = coefs.begin();

	for (u_it = u.begin(); u_it != u.end(); u_it++, coef_it++)
		for (size_t j = 0; j < result.getSize(); j++)
			result[j] += (*coef_it) * (*u_it)[j];
	return (result);
}
