#pragma once

#include "details/scalar_traits.hpp"

#include <cstddef>
#include <iomanip>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

template<numeric_scalar K>
class Matrix;

/**
 * @brief Dense vector container with basic linear algebra operations.
 */
template<numeric_scalar K>
class Vector
{
	static_assert(numeric_scalar<K>, "Vector only supports numeric scalar types");

	private:
		std::vector<K> fields;

	public:
		Vector( size_t n );
		Vector( std::initializer_list<K> values );
		Vector( const Vector& other ) = default;
		Vector& operator=( const Vector& other ) = default;
		~Vector() = default;

		/**
		 * @brief Return the vector dimension.
		 */
		size_t getSize() const;
		bool empty() const;
		K& operator[]( size_t index );
		const K& operator[]( size_t index ) const;

		template<numeric_scalar T>
		friend std::ostream& operator<<( std::ostream& os, const Vector<T>& v );

		void add( const Vector<K>& other );
		void sub( const Vector<K>& other );
		void scl( const K& scalar );
		K dot( const Vector<K>& v ) const;
		double norm_1() const;
		double norm() const;
		double norm_inf() const;
};

template<numeric_scalar K>
Vector<K> linear_combination( std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs );

template<numeric_scalar K>
Vector<K> linear_combination( const std::vector<Vector<K>>& u, const std::vector<K>& coefs );

template<numeric_scalar K>
K lerp( K a, K b, double t );

template<numeric_scalar K>
Vector<K> lerp( const Vector<K>& u, const Vector<K>& v, double t );

template<numeric_scalar K>
auto angle_cos( const Vector<K>& u, const Vector<K>& v );

template<numeric_scalar K>
Vector<K> cross_product( const Vector<K>& u, const Vector<K>& v );

#include "details/vector_base.tpp"
#include "details/vector_operations.tpp"
#include "details/vector_algorithms.tpp"
