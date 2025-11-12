/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Determinant.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:04:07 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 14:03:40 by rrichard         ###   ########.fr       */
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

	K			det = K(1), total = K(1);
	size_t		index;

	for (size_t	i = 0; i < _rows; i++)
	{
		index = i;
		while (index < _rows && mat(index, i) == K(0))
			index++;
		if (index == _rows)
			return (K(0));
		if (index != i)
		{
			mat.swap_rows(index, i);
			det = -det;
		}
		const K pivot = mat(i, i);
		for (size_t j = i + 1; j < _rows; j++)
		{
			const K a = mat(j, i);
			if (a == K(0))
				continue ;
			for (size_t k = i; k < _rows; k++)
				mat(j, k) = (pivot * mat(j, k)) - (a * mat(i, k));
			total *= pivot;
		}
	}
	for (size_t i = 0; i < _rows; i++)
		det *= mat(i, i);
	return (det / total);
}