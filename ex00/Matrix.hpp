/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:28:09 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/05 14:26:52 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Vector.hpp"
#include <sstream>

template<is_arithmetic K>
class Matrix
{
	private:
		std::vector<K> elements;
		size_t			_rows;
		size_t			_cols;
	
	public:
		Matrix( size_t rows, size_t cols )
		{
			this->elements = std::vector<K>((rows * cols), K(0));
			this->_rows = rows;
			this->_cols = cols;
		}
		Matrix( std::initializer_list<std::initializer_list<K>> values )
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
		Matrix( const Matrix& other ) = default;
		Matrix& operator=( const Matrix& other ) = default;	
		~Matrix() = default;

		void	add( const Matrix& m )
		{
			if (m._cols != this->_cols || m._rows != this->_rows)
				throw std::runtime_error("Error: Matrices must have the same dimensions for addition");
			for (size_t i = 0; i < elements.size(); i++)
			{
				this->elements[i] += m.elements[i];
			}
		}
		void	sub( const Matrix& m )
		{
			if (m._cols != this->_cols || m._rows != this->_rows)
				throw std::runtime_error("Error: Matrices must have the same dimensions for addition");
			for (size_t i = 0; i < elements.size(); i++)
			{
				this->elements[i] -= m.elements[i];
			}
		}
		void	scl( const K& scalar )
		{
			for (auto& it : elements)
				it *= scalar;
		}
		
		size_t	getSize() const
		{
			return (this->_cols * this->_rows);
		}
		size_t	getRows() const
		{
			return (this->_rows);
		}
		size_t	getCols() const
		{
			return (this->_cols);
		}
		bool	hasSameDim( const Matrix& other ) const
		{
			return (this->_rows == other._rows && this->_cols == other._cols);
		}
		bool	empty() const
		{
			return (elements.empty());
		}

		
		K&	at( size_t	row, size_t col )
		{
			if (row >= _rows)
			{
				std::stringstream ss;
				ss << row;
				throw std::out_of_range("Matrix::at row: " + std::string(ss.str()) + " index out of range: ");
			}
			else if (col >= _cols)
			{
				std::stringstream ss;
				ss << col;
				throw std::out_of_range("Matrix::at col: " + std::string(ss.str()) + " index out of range: ");
			}
			return (elements[row * _cols + col]);
		}
		const K&	at( size_t	row, size_t col ) const
		{
			if (row >= _rows)
			{
				std::stringstream ss;
				ss << row;
				throw std::out_of_range("Matrix::at: " + std::string(ss.str()) + " index out of range: ");
			}
			else if (col >= _cols)
			{
				std::stringstream ss;
				ss << col;
				throw std::out_of_range("Matrix::at: " + std::string(ss.str()) + " index out of range: ");
			}
			return (elements[row * _cols + col]);
		}
		K&	findValueMaxAbsColumn( size_t col )
		{
			K	maxAbsValue = K(0);
			
			for (size_t i = 0; i < _rows; i++)
			{
				K currentAbsValue = this->at(i, col) < 0 ? -this->at(i, col) : this->at(i, col);
				
				if (currentAbsValue > maxAbsValue)
					maxAbsValue = currentAbsValue;
			}
			return (maxAbsValue);
		}
		const K&	findValueMaxAbsColumn( size_t col ) const
		{
			K	maxAbsValue = K(0);
			
			for (size_t i = 0; i < _rows; i++)
			{
				K currentAbsValue = this->at(i, col) < 0 ? -this->at(i, col) : this->at(i, col);
				
				if (currentAbsValue > maxAbsValue)
					maxAbsValue = currentAbsValue;
			}
			return (maxAbsValue);
		}
		size_t	findIndexMaxAbsColumn( size_t col, size_t start_row )
		{
			K		maxAbsValue = K(0);
			size_t	index = -1;
			
			for (size_t i = start_row; i < _rows; i++)
			{
				K currentAbsValue = this->at(i, col) < 0 ? -this->at(i, col) : this->at(i, col);
				
				if (currentAbsValue > maxAbsValue)
				{
					maxAbsValue = currentAbsValue;
					index = i;
				}
			}
			return (index);
		}
		K&	operator()( size_t row, size_t col )
		{
			return (at(row, col));
		}
		const K&	operator()( size_t row, size_t col ) const
		{
			return (at(row, col));
		}
		K&	operator[]( size_t index )
		{
			if (index >= this->getSize())
				throw std::runtime_error("Error: index out of bound.");
			return (this->elements[index]);
		}
		const K&	operator[]( size_t index ) const
		{
			if (index >= this->getSize())
				throw std::runtime_error("Error: index out of bound.");
			return (this->elements[index]);
		}

		friend std::ostream& operator<<( std::ostream& os, const Matrix& m )
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
		// ex07
		Vector<K>	mul_vec( const Vector<K>& vec ) const;
		Matrix<K>	mul_mat( const Matrix<K>& mat ) const;
		// ex08
		K			trace() const;
		// ex09
		Matrix<K>	transpose() const;
		// ex10
		Matrix<K>	row_echelon();
		void		swap_rows( size_t, size_t );
};

#include "../ex07/Multiply.tpp"
#include "../ex08/Trace.tpp"
#include "../ex09/Transpose.tpp"
#include "../ex10/RowEchelon.tpp"