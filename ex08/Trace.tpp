/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Trace.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:49:14 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 14:03:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../Matrix.hpp"

template<is_arithmetic K>
K	Matrix<K>::trace() const
{
	if (this->_rows != this->_cols)
		throw std::runtime_error("Error: trace needs square matrix");

	K result = K(0);

	for (size_t i = 0; i < this->_rows; i++)
		result += this->at(i, i);
	return (result);
}