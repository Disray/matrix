/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddSubScl.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:05:24 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 14:20:03 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Matrix.hpp"


template<is_arithmetic K>
void	Matrix<K>::add( const Matrix<K>& m )
{
	if (m._cols != this->_cols || m._rows != this->_rows)
		throw std::runtime_error("Error: Matrices must have the same dimensions for addition");
	for (size_t i = 0; i < elements.size(); i++)
		this->elements[i] += m.elements[i];
}

template<is_arithmetic K>
void	Matrix<K>::sub( const Matrix<K>& m )
{
	if (m._cols != this->_cols || m._rows != this->_rows)
		throw std::runtime_error("Error: Matrices must have the same dimensions for substraction");
	for (size_t i = 0; i < elements.size(); i++)
		this->elements[i] -= m.elements[i];
}

template<is_arithmetic K>
void	Matrix<K>::scl( const K& scalar )
{
	for (auto& it : elements)
		it *= scalar;
}