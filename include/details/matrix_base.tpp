#pragma once

template<numeric_scalar K>
Matrix<K>::Matrix( size_t rows, size_t cols )
{
	this->elements = std::vector<K>((rows * cols), K(0));
	this->_rows = rows;
	this->_cols = cols;
}

template<numeric_scalar K>
Matrix<K>::Matrix( std::initializer_list<std::initializer_list<K>> values )
{
	if (values.size() == 0)
	{
		_rows = 0;
		_cols = 0;
		elements.clear();
		return ;
	}
	_rows = values.size();
	_cols = values.begin()->size();
	for (const auto& row : values)
	{
		if (row.size() != _cols)
			throw std::runtime_error("Error: inconsistent row size");
	}
	elements.reserve(_rows * _cols);
	for (const auto& row : values)
		elements.insert(elements.end(), row.begin(), row.end());
}

template<numeric_scalar K>
Matrix<K>::Matrix( size_t n )
{
	this->elements = std::vector<K>(n * n, K(0));
	this->_rows = n;
	this->_cols = n;
}

template<numeric_scalar K>
size_t Matrix<K>::getSize() const
{
	return (this->_cols * this->_rows);
}

template<numeric_scalar K>
size_t Matrix<K>::getRows() const
{
	return (this->_rows);
}

template<numeric_scalar K>
size_t Matrix<K>::getCols() const
{
	return (this->_cols);
}

template<numeric_scalar K>
bool Matrix<K>::hasSameDim( const Matrix& other ) const
{
	return (this->_rows == other._rows && this->_cols == other._cols);
}

template<numeric_scalar K>
bool Matrix<K>::empty() const
{
	return (elements.empty());
}

template<numeric_scalar K>
K& Matrix<K>::at( size_t row, size_t col )
{
	if (row >= this->_rows || col >= this->_cols)
		throw std::out_of_range("Matrix::at: index out of range: ");
	return (elements[row * _cols + col]);
}

template<numeric_scalar K>
const K& Matrix<K>::at( size_t row, size_t col ) const
{
	if (row >= this->_rows || col >= this->_cols)
		throw std::out_of_range("Matrix::at: index out of range: ");
	return (elements[row * _cols + col]);
}

template<numeric_scalar K>
K& Matrix<K>::operator()( size_t row, size_t col )
{
	return (at(row, col));
}

template<numeric_scalar K>
const K& Matrix<K>::operator()( size_t row, size_t col ) const
{
	return (at(row, col));
}

template<numeric_scalar K>
K& Matrix<K>::operator[]( size_t index )
{
	if (index >= this->getSize())
		throw std::runtime_error("Error: index out of bound.");
	return (this->elements[index]);
}

template<numeric_scalar K>
const K& Matrix<K>::operator[]( size_t index ) const
{
	if (index >= this->getSize())
		throw std::runtime_error("Error: index out of bound.");
	return (this->elements[index]);
}

template<numeric_scalar T>
std::ostream& operator<<( std::ostream& os, const Matrix<T>& m )
{
	for (size_t i = 0; i < m.elements.size(); i++)
	{
		if (i % m._cols == 0)
			os << "[";
		os << m.elements[i];
		if (i % m._cols == m._cols - 1)
			os << "]" << std::endl;
		else
			os << ", ";
	}
	return (os);
}
