#pragma once

#include <algorithm>
#include <cmath>

template<numeric_scalar K>
void Vector<K>::add( const Vector<K>& other )
{
	if (other.getSize() != this->getSize())
		throw std::runtime_error("Vectors have different dimensions");
	for (size_t i = 0; i < this->getSize(); i++)
		this->fields[i] += other[i];
}

template<numeric_scalar K>
void Vector<K>::sub( const Vector<K>& other )
{
	if (other.getSize() != this->getSize())
		throw std::runtime_error("Vectors have different dimensions");
	for (size_t i = 0; i < this->getSize(); i++)
		this->fields[i] -= other[i];
}

template<numeric_scalar K>
void Vector<K>::scl( const K& scalar )
{
	for (size_t i = 0; i < this->getSize(); i++)
		this->fields[i] *= scalar;
}

template<numeric_scalar K>
K Vector<K>::dot( const Vector<K>& v ) const
{
	if (this->getSize() != v.getSize())
		throw std::runtime_error("Error: input vectors must have the same size for dot product");
	K result = K(0);

	for (size_t i = 0; i < this->getSize(); i++)
	{
		if constexpr (std::is_arithmetic_v<K>)
			result = std::fma(this->fields[i], v[i], result);
		else
			result += fields[i] * v[i].conj();
	}
	return (result);
}

template<numeric_scalar K>
double Vector<K>::norm_1() const
{
	double result = 0.0;

	for (size_t i = 0; i < this->getSize(); i++)
		result += scalar_abs(this->fields[i]);
	return (result);
}

template<numeric_scalar K>
double Vector<K>::norm() const
{
	double result = 0.0;

	for (size_t i = 0; i < this->getSize(); i++)
		result += scalar_norm2(this->fields[i]);
	return (std::pow(result, 0.5));
}

template<numeric_scalar K>
double Vector<K>::norm_inf() const
{
	double result = 0.0;

	for (size_t i = 0; i < this->getSize(); i++)
		result = std::max(result, scalar_abs(this->fields[i]));
	return (result);
}
