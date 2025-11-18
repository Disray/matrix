/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAddSubScl.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:38:44 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/15 18:43:34 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<is_arithmetic K>
void	Vector<K>::add( const Vector<K>& other )
{
	if (other.getSize() != this->getSize())
		throw std::runtime_error("Vectors have different dimensions");
	auto oit = other.fields.begin();
	for (auto it = fields.begin(); it != fields.end(); it++, oit++)
		*it += *oit;
}

template<is_arithmetic K>
void	Vector<K>::sub( const Vector<K>& other )
{
	if (other.getSize() != this->getSize())
		throw std::runtime_error("Vectors have different dimensions");
	auto oit = other.fields.begin();
	for (auto it = fields.begin(); it != fields.end(); it++, oit++)
		*it -= *oit;
}

template<is_arithmetic K>
void	Vector<K>::scl( const K& scalar )
{
	for (auto it = fields.begin(); it != fields.end(); it++)
		*it *= scalar;
}