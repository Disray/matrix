/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:31:16 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/13 14:13:25 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<is_arithmetic K>
K	Vector<K>::dot( const Vector<K>& v ) const
{
	if (this->getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for dot product");
	K	result = K(0);

	for (size_t i = 0; i < this->getSize(); i++)
	{
		if constexpr (std::is_arithmetic_v<K>)
			result = std::fma(this->fields[i], v[i], result);
		else
			result += std::conj(v[i]) * fields[i];
	}
	return (result);
}
