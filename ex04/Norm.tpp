/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:44:05 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:12:26 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"

template<is_arithmetic K>
K	Vector<K>::norm_1() const
{
	K	result = K(0);

	for (size_t i = 0; i < this->getSize(); i++)
		result += this->fields[i] < 0 ? -this->fields[i] : this->fields[i];
	return (result);
}

template<is_arithmetic K>
K	Vector<K>::norm() const
{
	K	result = K(0);

	for (size_t i = 0; i < this->getSize(); i++)
		result = std::fma(this->fields[i], this->fields[i], result);
	result = std::pow(result, K(0.5));
	return (result);
}

template<is_arithmetic K>
K	Vector<K>::norm_inf() const
{
	K result = K(0);

	for (size_t i = 0; i < this->getSize(); i++)
		result = std::max(result, this->fields[i] < 0 ? -this->fields[i] : this->fields[i]);
	return (result);
}