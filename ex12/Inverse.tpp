/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inverse.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:33:25 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/06 15:10:11 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ex00/Matrix.hpp"

template<is_arithmetic K>
std::expected<Matrix<K>, std::string>	Matrix<K>::inverse() const
{
	Matrix<K>			result = *this;
	Matrix<K>			id = result.identity();
	size_t				row = 0, col = 0, i_max;
	std::vector<size_t>	pivot_col;

	while (row < _rows && col < result._cols)
	{
		i_max = result.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			col++;
		else
		{
			result.swap_rows(row, i_max);
			id.swap_rows(row, i_max);
			K pivot = result(row, col);
			result.scale_row(row, K(1) / pivot);
			id.scale_row(row, K(1) / pivot);
			pivot_col.push_back(col);
			for (size_t i = row + 1; i < result._rows; ++i)
			{
				K scale = result(i, col);
				result.add_row_multiple(i, row, scale);
				id.add_row_multiple(i, row, scale);
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
			if (factor == K(0))
				continue;
			result.add_row_multiple(i, r, factor);
			id.add_row_multiple(i, r, factor);
		}
	}
	if (pivot_col.size() != result._cols)
		return (std::unexpected(std::string("singular matrix")));
	return (id);
}

template<is_arithmetic K>
Matrix<K>	Matrix<K>::identity()
{
	Matrix<K>	id(_rows, _cols);
	
	for (size_t i = 0; i < _rows; i++)
		id(i, i) = K(1);
	return (id);
}