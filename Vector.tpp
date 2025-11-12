/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:12:52 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:15:26 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Vector.hpp"

template<is_arithmetic K>
Vector<K>::Vector( size_t n )
{
	this->fields = std::vector<K>(n, K(0));
}

template<is_arithmetic K>
Vector<K>::Vector( std::initializer_list<K> values )
{
	this->fields.assign(values.begin(), values.end());
}

template<is_arithmetic K>
size_t	Vector<K>::getSize() const
{
	return (this->fields.size());
}

template<is_arithmetic K>
bool	Vector<K>::empty() const
{
	return (fields.empty());
}

template<is_arithmetic K>
K&	Vector<K>::operator[]( size_t index )
{
	if (index >= this->getSize())
		throw std::runtime_error("Error: index out of bound.");
	return (this->fields[index]);
}

template<is_arithmetic K>
const K&	Vector<K>::operator[]( size_t index ) const
{
	if (index >= this->getSize())
		throw std::runtime_error("Error: index out of bound.");
	return (this->fields[index]);
}

template<is_arithmetic T>
std::ostream&	operator<<( std::ostream& os, const Vector<T>& v )
{
	for (auto& k : v.fields)
		os << std::fixed << std::setprecision(1) << "[" << k << "]" << std::endl;
	return (os);
}