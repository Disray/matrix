/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrichard <rrichard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:27:58 by rrichard          #+#    #+#             */
/*   Updated: 2025/11/18 19:26:20 by rrichard         ###   ########.fr       */
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
		double re = z.Re;
		double im = z.Im;

		if (im == 0.0)
			os << re;
		else if (re == 0.0)
			os << im << 'i';
		else
		{
			if (im < 0)
			{
				if (im == -1)
					os << re << " - " << 'i';
				else
					os << re << " - " << -im << 'i';
			}
			else
			{
				if (im == 1)
					os << re << " + " << 'i';
				else
					os << re << " + " << im << 'i';
			}
		}
		return (os);
	}
};
