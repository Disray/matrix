/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Determinant.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:04:07 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 11:26:25 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Matrix.hpp"

template<is_arithmetic K>
K	Matrix<K>::determinant()
{
	if (_rows != _cols)
		throw std::runtime_error("Error: Matrix::determinant: need square matrix for determinant");
	
	Matrix<K>	mat = *this;

	K		det = K(1);
	size_t	swaps = 0;
	size_t	row = 0, col = 0, i_max;

	while (row < mat._rows && col < mat._cols)
	{
		i_max = mat.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			return (K(0));
		if (i_max != row)
		{
			mat.swap_rows(row, i_max);
			swaps++;
		}
		K pivot = mat(row, col);
		det *= pivot;
		for (size_t i = row + 1; i < mat._rows; i++)
		{
			K scale = mat(i, col) / pivot;
			for (size_t j = col; j < mat._cols; j++)
				mat(i, j) -= scale * mat(row, j);
		}
		row++;
		col++;
	}
	if (swaps % 2 != 0)
		det = -det;
	return (det);
}