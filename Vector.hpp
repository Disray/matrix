/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:02 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/12 15:39:02 by rrichard         ###   ########.fr       */
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
# include <cmath>

template<typename K>
concept is_arithmetic = std::is_arithmetic_v<K>;

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
		K						norm_1() const;
		K						norm() const;
		K						norm_inf() const;
};

#include "Vector.tpp"
#include "./ex00/VAddSubScl.tpp"
#include "./ex03/Dot.tpp"
#include "./ex04/Norm.tpp"

#endif // VECTOR_HPP