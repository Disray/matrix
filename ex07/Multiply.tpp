/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiply.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:47:19 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:12:26 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Matrix.hpp"
#include "../Vector.hpp"

template<is_arithmetic K>
Vector<K>	Matrix<K>::mul_vec( const Vector<K>& vec ) const
{
	if (this->_cols != vec.getSize())
		throw std::runtime_error("Error: wrong dimensions for matrix multiplication");

	Vector<K>	result(this->_rows);

	for (size_t i = 0; i < this->_rows; i++)
	{
		K	sum = K(0);

		for (size_t j = 0; j < this->_cols; j++)
			sum = std::fma(this->operator()(i, j), vec[j], sum);
		result[i] = sum;
	}
	return (result);
}

template<is_arithmetic K>
Matrix<K>	Matrix<K>::mul_mat( const Matrix<K>& mat ) const
{
	if (this->_cols != mat.getRows())
		throw std::runtime_error("Error: wrong dimensions for matrix multiplication");
		
	Matrix<K>	result(this->_rows, this->_cols);

	for (size_t i = 0; i < this->_rows; i++)
	{
		for (size_t j = 0; j < mat.getCols(); j++)
		{
			K sum = K(0);

			for (size_t h = 0; h < mat.getRows(); h++)
				sum = std::fma(this->operator()(i, h), mat(h, j), sum);
			result(i, j) = sum;
		}
	}
	return (result);
}
