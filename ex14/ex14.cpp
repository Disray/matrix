/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:46:20 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 14:03:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Matrix.hpp"
#include <fstream>

Matrix<float>	projection(  float fov, float ratio, float near, float far )
{
	// const float 	DEG2RAD = M_PI / 180;
	// float			tangent = tan(fov / 2 * DEG2RAD);
	// float			top = near * tangent;
	// float			right = top * ratio;

	Matrix<float>	matrix(4);

	// matrix[0] = near / right;
	matrix(0, 0) = (1 / tan(fov / 2)) / ratio;
	matrix(1, 1) = 1 / (tan(fov / 2));
	// matrix[5] = near / top;
	// matrix[10] = far / (far - near);
	matrix(2, 2) = far / (near - far);
	matrix(2, 3) = -1.0f;
	// matrix[11] = 1.0f;
	matrix(3, 2) = near * far / (near - far);
	matrix(3, 3) = 0;
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
				ofs << ", ";
		}
		ofs << std::endl;
	}
	ofs.close();
}