#pragma once

#include <cmath>

template<numeric_scalar K>
void Matrix<K>::add( const Matrix<K>& m )
{
	if (m._cols != this->_cols || m._rows != this->_rows)
		throw std::runtime_error("Error: Matrices must have the same dimensions for addition");
	for (size_t i = 0; i < elements.size(); i++)
		this->elements[i] += m.elements[i];
}

template<numeric_scalar K>
void Matrix<K>::sub( const Matrix<K>& m )
{
	if (m._cols != this->_cols || m._rows != this->_rows)
		throw std::runtime_error("Error: Matrices must have the same dimensions for substraction");
	for (size_t i = 0; i < elements.size(); i++)
		this->elements[i] -= m.elements[i];
}

template<numeric_scalar K>
void Matrix<K>::scl( const K& scalar )
{
	for (size_t i = 0; i < this->getSize(); i++)
		this->elements[i] *= scalar;
}

template<numeric_scalar K>
Vector<K> Matrix<K>::mul_vec( const Vector<K>& vec ) const
{
	if (this->_cols != vec.getSize())
		throw std::runtime_error("Error: wrong dimensions for matrix multiplication");

	Vector<K> result(this->_rows);

	for (size_t i = 0; i < this->_rows; i++)
	{
		K sum = K(0);

		for (size_t j = 0; j < this->_cols; j++)
		{
			if constexpr (std::is_arithmetic_v<K>)
				sum = std::fma(this->at(i, j), vec[j], sum);
			else
				sum += this->at(i, j) * vec[j];
		}
		result[i] = sum;
	}
	return (result);
}

template<numeric_scalar K>
Matrix<K> Matrix<K>::mul_mat( const Matrix<K>& mat ) const
{
	if (this->_cols != mat.getRows())
		throw std::runtime_error("Error: wrong dimensions for matrix multiplication");

	Matrix<K> result(this->_rows, this->_cols);

	for (size_t i = 0; i < this->_rows; i++)
	{
		for (size_t j = 0; j < mat.getCols(); j++)
		{
			K sum = K(0);

			for (size_t h = 0; h < mat.getRows(); h++)
			{
				if constexpr (std::is_arithmetic_v<K>)
					sum = std::fma(this->at(i, h), mat(h, j), sum);
				else
					sum += this->at(i, h) * mat(h, j);
			}
			result(i, j) = sum;
		}
	}
	return (result);
}

template<numeric_scalar K>
K Matrix<K>::trace() const
{
	if (this->_rows != this->_cols)
		throw std::runtime_error("Error: trace needs square matrix");

	K result = K(0);

	for (size_t i = 0; i < this->_rows; i++)
		result += this->at(i, i);
	return (result);
}

template<numeric_scalar K>
Matrix<K> Matrix<K>::transpose() const
{
	Matrix<K> result(_cols, _rows);

	for (size_t j = 0; j < this->_cols; j++)
	{
		for (size_t i = 0; i < this->_rows; i++)
			result(j, i) = this->at(i, j);
	}
	return (result);
}
