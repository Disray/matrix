/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:46:20 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/08 11:01:13 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ex00/Matrix.hpp"
#include <fstream>

Matrix<float>	projection(  float fov, float ratio, float near, float far )
{
	const float 	DEG2RAD = acos(-1.0f / 180);
	float			tangent = tan(fov / 2 * DEG2RAD);
	float			top = near * tangent;
	float			right = top * ratio;

	Matrix<float>	matrix(4, 4);

	matrix[0] = near / right;
	matrix[5] = near / top;
	matrix[10] = -(far + near) / (far - near);
	matrix[11] = -1.0f;
	matrix[14] = -(2.0f * far * near) / (far - near);
	matrix[15] = 0;
	return (matrix);
}

int	main( int argc, char **argv )
{
	if (argc != 5)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	float fov, ratio, near, far;
	std::istringstream(argv[1]) >> fov;
	std::istringstream(argv[2]) >> ratio;
	std::istringstream(argv[3]) >> near;
	std::istringstream(argv[4]) >> far;
	Matrix<float> result = projection(fov, ratio, near, far);
	std::ofstream ofs("proj");
	if (!ofs)
	{
		std::cerr << "Failed to open output file." << std::endl;
		return (1);
	}
	for (size_t i = 0; i < result.getRows(); ++i)
	{
		for (size_t j = 0; j < result.getCols(); ++j)
		{
			ofs << result(i, j);
			if (j + 1 < result.getCols())
				ofs << " ";
		}
		ofs << std::endl;
	}
	ofs.close();
}