#pragma once

#include "Matrix.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

inline bool approx_equal( double lhs, double rhs, double eps = 1e-6 )
{
	return (std::fabs(lhs - rhs) <= eps);
}

inline bool approx_equal( float lhs, float rhs, double eps = 1e-6 )
{
	return (std::fabs(lhs - rhs) <= eps);
}

inline bool approx_equal( const Complex& lhs, const Complex& rhs, double eps = 1e-6 )
{
	return (approx_equal(lhs.Re, rhs.Re, eps) && approx_equal(lhs.Im, rhs.Im, eps));
}

template<typename T>
void expect_equal( const T& actual, const T& expected, const std::string& message )
{
	if (!(actual == expected))
		throw std::runtime_error(message);
}

inline void expect_equal( double actual, double expected, const std::string& message, double eps = 1e-6 )
{
	if (!approx_equal(actual, expected, eps))
		throw std::runtime_error(message);
}

inline void expect_equal( float actual, float expected, const std::string& message, double eps = 1e-6 )
{
	if (!approx_equal(actual, expected, eps))
		throw std::runtime_error(message);
}

inline void expect_equal( const Complex& actual, const Complex& expected, const std::string& message, double eps = 1e-6 )
{
	if (!approx_equal(actual, expected, eps))
		throw std::runtime_error(message);
}

template<typename K>
void expect_vector_equal( const Vector<K>& actual, const Vector<K>& expected, const std::string& message )
{
	expect_equal(actual.getSize(), expected.getSize(), message + " (size)");
	for (size_t i = 0; i < actual.getSize(); ++i)
		expect_equal(actual[i], expected[i], message + " (index " + std::to_string(i) + ")");
}

template<typename K>
void expect_matrix_equal( const Matrix<K>& actual, const Matrix<K>& expected, const std::string& message )
{
	expect_equal(actual.getRows(), expected.getRows(), message + " (rows)");
	expect_equal(actual.getCols(), expected.getCols(), message + " (cols)");
	for (size_t i = 0; i < actual.getRows(); ++i)
	{
		for (size_t j = 0; j < actual.getCols(); ++j)
			expect_equal(actual(i, j), expected(i, j), message + " (" + std::to_string(i) + "," + std::to_string(j) + ")");
	}
}

#define RUN_TEST(name)                                                                 \
	do                                                                                 \
	{                                                                                  \
		try                                                                            \
		{                                                                              \
			name();                                                                    \
			std::cout << "[OK] " #name << std::endl;                                   \
		}                                                                              \
		catch (const std::exception& error)                                            \
		{                                                                              \
			std::cerr << "[FAIL] " #name ": " << error.what() << std::endl;            \
			return (EXIT_FAILURE);                                                     \
		}                                                                              \
	} while (false)
