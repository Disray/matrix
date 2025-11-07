/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rank.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:33:59 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/07 11:42:14 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ex00/Matrix.hpp"

template<is_arithmetic K>
size_t	Matrix<K>::rank()
{
	Matrix<K>	Re = row_echelon();
	size_t		rank = 0;

	for (size_t i = 0; i < Re._rows; i++)
	{
		for (size_t	j = i; j < Re._cols; j++)
		{
			if (Re(i, j) != K(0))
			{
				rank++;
				break;
			}
		}
	}
	return (rank);
}