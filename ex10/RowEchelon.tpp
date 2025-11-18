/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RowEchelon.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:13:24 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/18 19:23:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Matrix.hpp"
#include "../ex05/AngleCos.tpp"
#include "../ex04/Norm.tpp"

double	scalar_norm2( const double& x )
{
	return (x * x);
}

double	scalar_norm2( const float& x )
{
	return (x * x);
}

double	scalar_norm2( const Complex& z )
{
	return (z.Re * z.Re + z.Im * z.Im);
}

template<typename K>
double	scalar_norm2( const K& x )
{
	return (static_cast<double>(x) * static_cast<double>(x));
}

template<typename K>
bool	scalar_is_zero( const K& x, double eps = 1e-9 )
{
	return (scalar_norm2(x) < eps * eps);
}

template<is_arithmetic K>
Matrix<K>	Matrix<K>::row_echelon()
{
	Matrix<K>			result = *this;
	size_t				row = 0, col = 0, i_max;
	std::vector<size_t>	pivot_col;

	while (row < result._rows && col < result._cols)
	{
		i_max = result.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			col++;
		else
		{
			result.swap_rows(row, i_max);
			K	pivot = result(row, col);
			result.scale_row(row, K(1) / pivot);
			pivot_col.push_back(col);
			for (size_t i = row + 1; i < result._rows; ++i)
			{
				K	scale = result(i, col);
				result.add_row_multiple(i, row, scale);
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
			K	scale = result(i, c);
			result.add_row_multiple(i, r, scale);
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
		std::swap(this->at(row1, j), this->at(row2, j));
}

template<is_arithmetic K>
void	Matrix<K>::scale_row( size_t row, K scale )
{
	for (size_t i = 0; i < this->_cols; i++)
		this->at(row, i) *= scale;
}

template<is_arithmetic K>
void	Matrix<K>::add_row_multiple( size_t dest, size_t source, K k )
{
	for (size_t i = 0; i < this->_cols; i++)
		this->at(dest, i) -= this->at(source, i) * k;
}

template<is_arithmetic K>
size_t	Matrix<K>::findIndexMaxAbsColumn( size_t col, size_t start_row )
{
	double	bestNorm2 = 0.0;
	size_t	bestIndex = size_t(-1);
	double	eps = 1e-9;

	for (size_t i = start_row; i < _rows; i++)
	{
		double n2 = scalar_norm2(this->at(i, col));
		if (n2 > bestNorm2)
		{
			bestNorm2 = n2;
			bestIndex = i;
		}
	}

	if (bestNorm2 < eps * eps)
		return (size_t(-1));
	return (bestIndex);
}
