/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:02 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 15:55:10 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <vector>
# include <initializer_list>
# include <type_traits>
# include <cstddef>
# include <stdexcept>
# include <iomanip>
# include "./ex15/Complex.hpp"

template<typename T> 
struct is_complex : std::false_type {};

template<> 
struct is_complex<Complex> : std::true_type {};

template<typename K>
concept is_arithmetic = std::is_arithmetic_v<K> || is_complex<K>::value;

template<is_arithmetic K>
class Matrix;

template<is_arithmetic K>
class Vector
{
	private:
		std::vector<K>	fields;

	public:
		Vector( size_t n );
		Vector( std::initializer_list<K> values );
		Vector( const Vector& other ) = default;
		Vector&	operator=( const Vector& other ) = default;
		~Vector() = default;

		size_t					getSize() const;
		bool					empty() const;
		K&						operator[]( size_t index );
		const K&				operator[]( size_t index ) const;

		template<is_arithmetic T>
		friend std::ostream&	operator<<( std::ostream& os, const Vector<T>& v );

		// ex00
		void					add( const Vector<K>& other );
		void					sub( const Vector<K>& other );
		void					scl( const K& scalar );

		// ex03
		K						dot( const Vector<K>& v ) const;

		// ex04
		double					norm_1() const;
		double					norm() const;
		double					norm_inf() const;
};

template<is_arithmetic K>
Vector<K>	linear_combination( std::initializer_list<Vector<K>> u, std::initializer_list<K> coefs );
template<is_arithmetic K>
Vector<K>	linear_combination( const std::vector<Vector<K>>& u, const std::vector<K>& coefs );
template<is_arithmetic K>
K			lerp( K a, K b, double t );
template<is_arithmetic K>
Vector<K>	lerp( const Vector<K>& u, const Vector<K>& v, double t );
template<is_arithmetic K>
Matrix<K>	lerp( const Matrix<K>& u, const Matrix<K>& v, double t );
template<is_arithmetic K>
auto		angle_cos( const Vector<K>& u, const Vector<K>& v );
template<is_arithmetic K>
Vector<K>	cross_product( const Vector<K>& u, const Vector<K>& v );


#include "Vector.tpp"
#include "./ex00/VAddSubScl.tpp"
#include "./ex01/LinearCombination.tpp"
#include "./ex02/LinearInterpolation.tpp"
#include "./ex03/Dot.tpp"
#include "./ex04/Norm.tpp"
#include "./ex05/AngleCos.tpp"
#include "./ex06/CrossProduct.tpp"

#endif // VECTOR_HPP