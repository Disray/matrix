/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:28:09 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:09:40 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./ex00/Vector.hpp"
#include <sstream>
#include <expected>

template<is_arithmetic K>
class Matrix
{
	private:
		std::vector<K> elements;
		size_t			_rows;
		size_t			_cols;
	
	public:
		// Square matrix constructor
		Matrix( size_t n );
		// Rectangle matrix constructor
		Matrix( size_t n, size_t m );
		Matrix( std::initializer_list<std::initializer_list<K>> values );
		Matrix( const Matrix& other ) = default;
		Matrix& operator=( const Matrix& other ) = default;	
		~Matrix() = default;
		
		size_t					getSize() const;
		size_t					getRows() const;
		size_t					getCols() const;
		bool					hasSameDim( const Matrix& other ) const;
		bool					empty() const;
		K&						at( size_t	row, size_t col );
		const K&				at( size_t	row, size_t col ) const;
		K&						operator()( size_t row, size_t col );
		const K&				operator()( size_t row, size_t col ) const;
		K&						operator[]( size_t index );
		const K&				operator[]( size_t index ) const;

		template<is_arithmetic T>
		friend std::ostream&	operator<<( std::ostream& os, const Matrix<T>& m );

		// ex00
		void					add( const Matrix& m );
		void					sub( const Matrix& m );
		void					scl( const K& scalar );
		// ex07
		Vector<K>				mul_vec( const Vector<K>& vec ) const;
		Matrix<K>				mul_mat( const Matrix<K>& mat ) const;
		// ex08
		K						trace() const;
		// ex09
		Matrix<K>				transpose() const;
		// ex10
		Matrix<K>				row_echelon();
		void					swap_rows( size_t, size_t );
		void					scale_row( size_t, K );
		void					add_row_multiple( size_t, size_t, K );
		size_t					findIndexMaxAbsColumn( size_t col, size_t start_row );
		// ex11
		K						determinant();
		// ex12
		std::expected<Matrix<K>, std::string>	inverse() const;
		Matrix<K>				identity();
		// ex13
		size_t					rank();
};

#include "Matrix.tpp"
#include "./ex00/AddSubScl.tpp"
#include "./ex07/Multiply.tpp"
#include "./ex08/Trace.tpp"
#include "./ex09/Transpose.tpp"
#include "./ex10/RowEchelon.tpp"
#include "./ex11/Determinant.tpp"
#include "./ex12/Inverse.tpp"
#include "./ex13/Rank.tpp"
