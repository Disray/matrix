/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:28:09 by rrichard          #+#    #+#             */
/*   Updated: 2025/10/31 16:31:04 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include "Vector.hpp"

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
			this->elements = std::vector<K>((rows * cols), K{});
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
				os << std::fixed << std::setprecision(1) << m.elements[i];
				if (i % m._cols == m._cols - 1)
					os << "]" << std::endl;
				else
					os << ", ";
			}
			return (os);
		}
};

#endif // MATRIX_HPP