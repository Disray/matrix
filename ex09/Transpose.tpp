/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Transpose.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:10:19 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 14:03:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../Matrix.hpp"

template<is_arithmetic K>
Matrix<K>	Matrix<K>::transpose() const
{
	Matrix<K>	result(_cols, _rows);

	for (size_t j = 0; j < this->_cols; j++)
	{
		for (size_t i = 0; i < this->_rows; i++)
			result(j, i) = this->operator()(i, j);
	}
	return (result);
}