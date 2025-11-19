/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:27:58 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/19 14:08:02 by rrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

struct Complex
{
	double	Re;
	double	Im;

	Complex() : Re(0.0), Im(0.0) {}
	Complex( double r, double i ) : Re(r), Im(i) {}
	Complex( double re ) : Re(re), Im(0.0) {}
	
	Complex	conj() const
	{
		Complex z(0, 0);

		z.Re = this->Re;
		z.Im = -this->Im;
		return (z);
	}
	
	Complex	operator+( const Complex& other ) const noexcept
	{
		Complex z(0, 0);

		z.Re = this->Re + other.Re;
		z.Im = this->Im + other.Im;
		return (z);
	}
	Complex	operator-( const Complex& other ) const noexcept
	{
		Complex z(0, 0);

		z.Re = this->Re - other.Re;
		z.Im = this->Im - other.Im;
		return (z);
	}
	Complex	operator*( const Complex& other ) const noexcept
	{
		Complex	z(0, 0);

		z.Re = this->Re * other.Re - this->Im * other.Im;
		z.Im = this->Re * other.Im + this->Im * other.Re;
		return (z);
	}
	Complex	operator/( const Complex& other ) const noexcept
	{
		Complex z(0, 0);

		z.Re = (this->Re * other.Re + this->Im * other.Im) / (other.Re * other.Re + other.Im * other.Im);
		z.Im = (this->Im * other.Re - this->Re * other.Im) / (other.Re * other.Re + other.Im * other.Im);
		return (z);
	}
	Complex	operator-() const
	{
		return (Complex(-Re, -Im));
	}
	Complex& operator+=( const Complex& other ) noexcept
	{
		Re += other.Re;
		Im += other.Im;
		return (*this);
	}
	Complex& operator-=( const Complex& other ) noexcept
	{
		Re -= other.Re;
		Im -= other.Im;
		return (*this);
	}

	Complex&	operator*=( const Complex& other ) noexcept
	{
		double real = this->Re;
		double imag = this->Im;

		Re = real * other.Re - imag * other.Im;
		Im = real * other.Im + imag * other.Re;
		return (*this);
	}

	Complex&	operator/=( const Complex& other ) noexcept
	{
		double real = this->Re;
		double imag = this->Im;

		Re = (real * other.Re + imag * other.Im) / (other.Re * other.Re + other.Im * other.Im);
		Im = (imag * other.Re - real * other.Im) / (other.Re * other.Re + other.Im * other.Im);
		return (*this);
	}
	bool	operator==( const Complex& other ) const noexcept
	{
		return (this->Re == other.Re && this->Im == other.Im);
	}

	friend std::ostream&	operator<<( std::ostream& os, const Complex& z )
	{
		constexpr double eps = 1e-9;

		auto near = [&](double x, double target)
		{
			return (std::abs(x - target) < eps);
		};
		double re = z.Re;
		double im = z.Im;

		if (std::abs(im) < eps)
		{
			os << re;
			return (os);
		}
		if (std::abs(re) < eps)
		{
			if (near(im, 1))
				os << "i";
			else if (near(im, -1))
				os << "-i";
			else
				os << im << "i";
			return (os);
		}
		os << re << " ";
		if (near(im, 1))
			os << "+ i";
		else if (near(im, -1))
			os << " - i";
		else if (im > 0)
			os << "+ " << im << "i";
		else
			os << "- " << -im << "i";
		return (os);
	}
};

double	complex_absolute( const Complex& z )
{
	double	real_sq = z.Re * z.Re;
	double	imag_sq = z.Im * z.Im;

	return (std::pow(real_sq + imag_sq, 0.5));
}

template<typename T>
T	custom_abs( T a )
{
	return a >= 0 ? a : -a;
}

template<typename K>
double	scalar_abs( const K& x )
{
	if constexpr (std::is_arithmetic_v<K>)
		return (x < K(0) ? -static_cast<double>(x) : static_cast<double>(x));
	else
		return (complex_absolute(x));
}

double	scalar_norm2( const double& x )
{
	return (x * x);
}

double	scalar_norm2( const float& x )
{
	return (x * x);
}

double	scalar_norm2( const Complex& z )
{
	return (z.Re * z.Re + z.Im * z.Im);
}

template<typename K>
double	scalar_norm2( const K& x )
{
	return (static_cast<double>(x) * static_cast<double>(x));
}

template<typename K>
bool	scalar_is_zero( const K& x, double eps = 1e-9 )
{
	return (scalar_norm2(x) < eps * eps);
}