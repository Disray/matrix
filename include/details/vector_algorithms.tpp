#pragma once

#include <cmath>

template<numeric_scalar K>
Vector<K> linear_combination( std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs )
{
	return (linear_combination(std::vector<Vector<K>>(u.begin(), u.end()), std::vector<K>(coefs.begin(), coefs.end())));
}

template<numeric_scalar K>
Vector<K> linear_combination( const std::vector<Vector<K>>& u, const std::vector<K>& coefs )
{
	if (u.empty())
		throw std::runtime_error("Input vector is empty");
	if (u.size() != coefs.size())
		throw std::runtime_error("Inconsistent array size for linear combination");

	size_t expected_size = u[0].getSize();

	for (const auto& vec : u)
	{
		if (vec.getSize() != expected_size)
			throw std::runtime_error("Vectors have different sizes");
	}

	Vector<K> result(expected_size);

	for (size_t i = 0; i < u.size(); i++)
	{
		for (size_t j = 0; j < result.getSize(); j++)
			result[j] += coefs[i] * u[i][j];
	}
	return (result);
}

template<numeric_scalar K>
K lerp( K a, K b, double t )
{
	if constexpr (std::is_arithmetic_v<K>)
		return (std::fma(b - a, static_cast<K>(t), a));
	else
		return (a + (b - a) * static_cast<K>(t));
}

template<numeric_scalar K>
Vector<K> lerp( const Vector<K>& u, const Vector<K>& v, double t )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input vectors are empty");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for linear interpolation");

	Vector<K> result(u.getSize());

	for (size_t i = 0; i < u.getSize(); i++)
		result[i] = lerp(u[i], v[i], t);
	return (result);
}

template<numeric_scalar K>
auto angle_cos( const Vector<K>& u, const Vector<K>& v )
{
	const double eps = 1e-12;

	if (u.empty() || v.empty())
		throw std::runtime_error("Error: one or both input vectors are empty");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for cos angle calculation");

	K d = u.dot(v);
	double nu = u.norm();
	double nv = v.norm();

	if (custom_abs(nu) < eps || custom_abs(nv) < eps)
		throw std::runtime_error("Error: zero-length vector (cannot compute angle)");
	return (d / (nu * nv));
}

template<numeric_scalar K>
Vector<K> cross_product( const Vector<K>& u, const Vector<K>& v )
{
	if (u.empty() || v.empty())
		throw std::runtime_error("Error: empty vector");
	if (u.getSize() != v.getSize())
		throw std::runtime_error("Error: inconsistent vector dimensions");
	if (u.getSize() != 3)
		throw std::runtime_error("Error: cross_product requires 3-dimensional vectors");

	Vector<K> result(3);

	result[0] = (u[1] * v[2]) - (u[2] * v[1]);
	result[1] = (u[2] * v[0]) - (u[0] * v[2]);
	result[2] = (u[0] * v[1]) - (u[1] * v[0]);
	return (result);
}
