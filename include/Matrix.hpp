#pragma once

#include "Vector.hpp"

#include <optional>

/**
 * @brief Dense row-major matrix container with linear algebra routines.
 */
template<numeric_scalar K>
class Matrix
{
	static_assert(numeric_scalar<K>, "Matrix only supports numeric scalar types");

	private:
		std::vector<K> elements;
		size_t _rows;
		size_t _cols;

	public:
		Matrix( size_t n );
		Matrix( size_t n, size_t m );
		Matrix( std::initializer_list<std::initializer_list<K>> values );
		Matrix( const Matrix& other ) = default;
		Matrix& operator=( const Matrix& other ) = default;
		~Matrix() = default;

		size_t getSize() const;
		size_t getRows() const;
		size_t getCols() const;
		bool hasSameDim( const Matrix& other ) const;
		bool empty() const;
		K& at( size_t row, size_t col );
		const K& at( size_t row, size_t col ) const;
		K& operator()( size_t row, size_t col );
		const K& operator()( size_t row, size_t col ) const;
		K& operator[]( size_t index );
		const K& operator[]( size_t index ) const;

		template<numeric_scalar T>
		friend std::ostream& operator<<( std::ostream& os, const Matrix<T>& m );

		void add( const Matrix<K>& m );
		void sub( const Matrix<K>& m );
		void scl( const K& scalar );
		Vector<K> mul_vec( const Vector<K>& vec ) const;
		Matrix<K> mul_mat( const Matrix<K>& mat ) const;
		K trace() const;
		Matrix<K> transpose() const;
		Matrix<K> row_echelon();
		void swap_rows( size_t row1, size_t row2 );
		void scale_row( size_t row, K scale );
		void add_row_multiple( size_t dest, size_t source, K k );
		size_t findIndexMaxAbsColumn( size_t col, size_t start_row );
		K determinant();
		std::optional<Matrix<K>> inverse() const;
		Matrix<K> identity();
		size_t rank();
};

template<numeric_scalar K>
Matrix<K> lerp( const Matrix<K>& u, const Matrix<K>& v, double t );

Matrix<float> projection( float fov, float ratio, float near, float far );

#include "details/matrix_base.tpp"
#include "details/matrix_operations.tpp"
#include "details/matrix_decomposition.tpp"
#include "details/matrix_algorithms.tpp"
