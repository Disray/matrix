/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrossProduct.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:46:22 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/01 19:38:36 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ex00/Vector.hpp"

template<is_arithmetic K>
Vector<K>	cross_product( const Vector<K>& u, const Vector<K>& v )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: empty vector");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: inconsistent vector dimensions");
	if (u.getSize() != 3)
		throw std::runtime_error("Error: cross_product requires 3-dimensional vectors");

	Vector<K>	result(3);

	result[0] = (u[1] * v[2]) - (u[2] * v[1]);
	result[1] = (u[2] * v[0]) - (u[0] * v[2]);
	result[2] = (u[0] * v[1]) - (u[1] * v[0]); 
	return (result);
}
