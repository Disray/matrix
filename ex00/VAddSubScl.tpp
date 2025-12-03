/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VAddSubScl.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:38:44 by rrichard          #+#    #+#             */
/*   Updated: 2025/12/03 15:41:10 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Vector.hpp"

template<is_arithmetic K>
void	Vector<K>::add( const Vector<K>& other )
{
	if (other.getSize() != this->getSize())
		throw std::runtime_error("Vectors have different dimensions");
	for (size_t i = 0; i < this->getSize(); i++)
		this->fields[i] += other[i];
}

template<is_arithmetic K>
void	Vector<K>::sub( const Vector<K>& other )
{
	if (other.getSize() != this->getSize())
		throw std::runtime_error("Vectors have different dimensions");
	for (size_t i = 0; i < this->getSize(); i++)
		this->fields[i] -= other[i];
}

template<is_arithmetic K>
void	Vector<K>::scl( const K& scalar )
{
	for (size_t i = 0; i < this->getSize(); i++)
		this->fields[i] *= scalar;
}