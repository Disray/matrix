#pragma once

#include <cmath>

template<numeric_scalar K>
Matrix<K> lerp( const Matrix<K>& u, const Matrix<K>& v, double t )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input matrices are empty for linear interpolation");
	if (!u.hasSameDim(v))
		throw std::runtime_error("Error: input matrices must have the same dimensions for linear interpolation");

	Matrix<K> result(u.getCols(), u.getRows());

	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}

inline Matrix<float> projection( float fov, float ratio, float near, float far )
{
	float tangent = std::tan(fov / 2.0f);

	Matrix<float> matrix(4);

	matrix(0, 0) = 1.0f / (ratio * tangent);
	matrix(1, 1) = 1.0f / tangent;
	matrix(2, 2) = far / (near - far);
	matrix(2, 3) = (near * far) / (near - far);
	matrix(3, 2) = -1.0f;
	return (matrix);
}
