/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:31:16 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:11:33 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<is_arithmetic K>
K	Vector<K>::dot( const Vector<K>& v ) const
{
	if (this->getSize() != v.getSize())
		throw std::runtime_error("Vectors have different dimensions");
	K	result = K(0);

	for (size_t i = 0; i < this->getSize(); i++)
		result = std::fma(this->fields[i], v[i], result);
	return (result);
}
