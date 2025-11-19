/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AngleCos.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:46:22 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 09:50:26 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<is_arithmetic K>
auto	angle_cos( const Vector<K>& u, const Vector<K>& v )
{
	const double	eps = 1e-12;

	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input vectors are empty");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for cos angle calculation");

	K		d = u.dot(v);;
	double	nu = u.norm();
	double	nv = v.norm();

	if (custom_abs(nu) < eps || custom_abs(nv) < eps)
        throw std::runtime_error("Error: zero-length vector (cannot compute angle)");
	return (d / (nu * nv));
}
