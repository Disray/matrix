/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RowEchelon.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:13:24 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/05 14:23:34 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ex00/Matrix.hpp"

template<is_arithmetic K>
Matrix<K>	Matrix<K>::row_echelon()
{
	Matrix<K>	result = *this;
	size_t		row = 0, col = 0, i_max;
	std::vector<size_t>	pivot_col;

	while (row < _rows && col < _cols)
	{
		i_max = result.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			col++;
		else
		{
			result.swap_rows(row, i_max);
			K pivot = result(row, col);
			for (size_t j = col; j < this->_cols; j++)
				result(row, j) /= pivot;
			pivot_col.push_back(col);
			for (size_t i = row + 1; i < this->_rows; ++i)
			{
				K scale = result(i, col);
				result(i, col) = K(0);
				for (size_t j = col + 1; j < this->_cols; j++)
				{
					result(i, j) = result(i, j) - (result(row, j) * scale);
				}
			}
			col++;
			row++;
		}
	}
	for (size_t	r = row; r-- > 0;)
	{
		size_t	c = pivot_col[r];
		for (size_t i = 0; i < r; i++)
		{
			K factor = result(i, c);
			for (size_t j = c; j < _cols; j++)
				result(i, j) -= factor * result(r, j);
		}
	}
	return (result);
}

template<is_arithmetic K>
void	Matrix<K>::swap_rows( size_t row1, size_t row2 )
{
	if (row1 == row2)
		return ;

	for (size_t j = 0; j < _cols; j++)
		std::swap(elements[row1 * _cols + j], elements[row2 * _cols + j]);
}