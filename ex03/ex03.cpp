/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:37:18 by rrichard          #+#    #+#             */
/*   Updated: 2025/10/31 18:52:32 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex00/Vector.hpp"

int	main( void )
{
	Vector<float>	u({0.0f, 0.0f}), v({1.0f, 1.0f});
	std::cout << std::fixed << u.dot(v) << std::endl;
	
	Vector<float>	u1({1.0f, 1.0f}), v1({1.0f, 1.0f});
	std::cout << std::fixed << u1.dot(v1) << std::endl;
	
	Vector<float>	u2({-1.0f, 6.0f}), v2({3.0f, 2.0f});
	std::cout << std::fixed << u2.dot(v2) << std::endl;
	return (0);
}