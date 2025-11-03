/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:50:02 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/03 14:47:13 by rrichard         ###   ########.fr       */
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
		Vector( size_t n )
		{
			this->fields = std::vector<K>(n, K(0));
		}
		Vector( std::initializer_list<K> values )
		{
			this->fields.assign(values.begin(), values.end());
		}
		Vector( const Vector& other ) = default;
		Vector&	operator=( const Vector& other ) = default;
		~Vector() = default;

		size_t	getSize() const
		{
			return (this->fields.size());
		}
		bool	empty() const
		{
			return (fields.empty());
		}

		// ex00
		void	add( const Vector& other )
		{
			if (other.getSize() != this->getSize())
				throw std::runtime_error("Vectors have different dimensions");
			auto oit = other.fields.begin();
			for (auto it = fields.begin(); it != fields.end(); it++, oit++)
				*it += *oit;
		}
		void	sub( const Vector& other )
		{
			if (other.getSize() != this->getSize())
				throw std::runtime_error("Vectors have different dimensions");
			auto oit = other.fields.begin();
			for (auto it = fields.begin(); it != fields.end(); it++, oit++)
				*it -= *oit;
		}
		void	scl( const K& scalar )
		{
			for (auto it = fields.begin(); it != fields.end(); it++)
				*it *= scalar;
		}
		K		dot( const Vector<K>& v ) const;

		// ex04
		K	norm_1() const;
		K	norm() const;
		K	norm_inf() const;

		K&	operator[]( size_t index )
		{
			if (index >= this->getSize())
				throw std::runtime_error("Error: index out of bound.");
			return (this->fields[index]);
		}
		const K&	operator[]( size_t index ) const
		{
			if (index >= this->getSize())
				throw std::runtime_error("Error: index out of bound.");
			return (this->fields[index]);
		}
		friend std::ostream&	operator<<( std::ostream& os, const Vector& v )
		{
			for (auto& k : v.fields)
				os << std::fixed << std::setprecision(1) << "[" << k << "]" << std::endl;
			return (os);
		}
};

#include "../ex03/Dot.tpp"
#include "../ex04/Norm.tpp"

#endif // VECTOR_HPP