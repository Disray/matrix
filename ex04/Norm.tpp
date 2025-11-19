/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Norm.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:44:05 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 09:27:45 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Vector.hpp"

template<is_arithmetic K>
double	Vector<K>::norm_1() const
{
	double	result = 0.0;
	for (size_t i = 0; i < this->getSize(); i++)
		result += scalar_abs(this->fields[i]);
	return (result);
}

template<is_arithmetic K>
double	Vector<K>::norm() const
{
	double	result = 0.0;
	for (size_t i = 0; i < this->getSize(); i++)
		result += scalar_norm2(this->fields[i]);
	return (std::pow(result, 0.5));
}

template<is_arithmetic K>
double	Vector<K>::norm_inf() const
{
	double result = 0.0;
	for (size_t i = 0; i < this->getSize(); i++)
		result = std::max(result, scalar_abs(this->fields[i]));
	return (result);
}
