/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AngleCos.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:46:22 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:12:26 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<is_arithmetic K>
K	angle_cos( const Vector<K>& u, const Vector<K>& v )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: empty vector");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: inconsistent vector dimensions");

	K result = K(0);

	result = u.dot(v) / (u.norm() * v.norm());
	return (result);
}
