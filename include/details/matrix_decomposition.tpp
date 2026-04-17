#pragma once

template<numeric_scalar K>
Matrix<K> Matrix<K>::row_echelon()
{
	Matrix<K> result = *this;
	size_t row = 0;
	size_t col = 0;
	size_t i_max;
	std::vector<size_t> pivot_col;

	while (row < result._rows && col < result._cols)
	{
		i_max = result.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			col++;
		else
		{
			result.swap_rows(row, i_max);
			K pivot = result(row, col);
			result.scale_row(row, K(1) / pivot);
			pivot_col.push_back(col);
			for (size_t i = row + 1; i < result._rows; ++i)
			{
				K scale = result(i, col);
				result.add_row_multiple(i, row, scale);
			}
			col++;
			row++;
		}
	}
	for (size_t r = row; r-- > 0;)
	{
		size_t c = pivot_col[r];
		for (size_t i = 0; i < r; i++)
		{
			K scale = result(i, c);
			result.add_row_multiple(i, r, scale);
		}
	}
	return (result);
}

template<numeric_scalar K>
void Matrix<K>::swap_rows( size_t row1, size_t row2 )
{
	if (row1 == row2)
		return ;

	for (size_t j = 0; j < _cols; j++)
		std::swap(this->at(row1, j), this->at(row2, j));
}

template<numeric_scalar K>
void Matrix<K>::scale_row( size_t row, K scale )
{
	for (size_t i = 0; i < this->_cols; i++)
		this->at(row, i) *= scale;
}

template<numeric_scalar K>
void Matrix<K>::add_row_multiple( size_t dest, size_t source, K k )
{
	for (size_t i = 0; i < this->_cols; i++)
		this->at(dest, i) -= this->at(source, i) * k;
}

template<numeric_scalar K>
size_t Matrix<K>::findIndexMaxAbsColumn( size_t col, size_t start_row )
{
	double bestNorm2 = 0.0;
	size_t bestIndex = size_t(-1);
	double eps = 1e-9;

	for (size_t i = start_row; i < _rows; i++)
	{
		double n2 = scalar_norm2(this->at(i, col));
		if (n2 > bestNorm2)
		{
			bestNorm2 = n2;
			bestIndex = i;
		}
	}

	if (bestNorm2 < eps * eps)
		return (size_t(-1));
	return (bestIndex);
}

template<numeric_scalar K>
K Matrix<K>::determinant()
{
	if (_rows != _cols)
		throw std::runtime_error("Error: Matrix::determinant: need square matrix for determinant");

	Matrix<K> mat = *this;

	K det = K(1);
	size_t swaps = 0;
	size_t row = 0;
	size_t col = 0;
	size_t i_max;

	while (row < mat._rows && col < mat._cols)
	{
		i_max = mat.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			return (K(0));
		if (i_max != row)
		{
			mat.swap_rows(row, i_max);
			swaps++;
		}
		K pivot = mat(row, col);
		det *= pivot;
		for (size_t i = row + 1; i < mat._rows; i++)
		{
			K scale = mat(i, col) / pivot;
			for (size_t j = col; j < mat._cols; j++)
				mat(i, j) -= scale * mat(row, j);
		}
		row++;
		col++;
	}
	if (swaps % 2 != 0)
		det = -det;
	return (det);
}

template<numeric_scalar K>
std::optional<Matrix<K>> Matrix<K>::inverse() const
{
	Matrix<K> result = *this;
	Matrix<K> id = result.identity();
	size_t row = 0;
	size_t col = 0;
	size_t i_max;
	std::vector<size_t> pivot_col;

	while (row < _rows && col < result._cols)
	{
		i_max = result.findIndexMaxAbsColumn(col, row);
		if (i_max == size_t(-1))
			col++;
		else
		{
			result.swap_rows(row, i_max);
			id.swap_rows(row, i_max);
			K pivot = result(row, col);
			result.scale_row(row, K(1) / pivot);
			id.scale_row(row, K(1) / pivot);
			pivot_col.push_back(col);
			for (size_t i = row + 1; i < result._rows; ++i)
			{
				K scale = result(i, col);
				result.add_row_multiple(i, row, scale);
				id.add_row_multiple(i, row, scale);
			}
			col++;
			row++;
		}
	}
	for (size_t r = row; r-- > 0;)
	{
		size_t c = pivot_col[r];
		for (size_t i = 0; i < r; i++)
		{
			K factor = result(i, c);
			if (factor == K(0))
				continue ;
			result.add_row_multiple(i, r, factor);
			id.add_row_multiple(i, r, factor);
		}
	}
	if (pivot_col.size() != result._cols)
		return (std::nullopt);
	return (id);
}

template<numeric_scalar K>
Matrix<K> Matrix<K>::identity()
{
	Matrix<K> id(_rows, _cols);

	for (size_t i = 0; i < _rows; i++)
		id(i, i) = K(1);
	return (id);
}

template<numeric_scalar K>
size_t Matrix<K>::rank()
{
	Matrix<K> Re = row_echelon();
	size_t rank = 0;

	for (size_t i = 0; i < Re._rows; i++)
	{
		for (size_t j = i; j < Re._cols; j++)
		{
			if (Re(i, j) != K(0))
			{
				rank++;
				break ;
			}
		}
	}
	return (rank);
}
