#include "test_common.hpp"

static void test_determinant()
{
	Matrix<double> u{{8.0, 5.0, -2.0}, {4.0, 7.0, 20.0}, {7.0, 6.0, 1.0}};
	expect_equal(u.determinant(), -174.0, "determinant");
}

static void test_inverse()
{
	Matrix<double> diag3{
		{2.0, 0.0, 0.0},
		{0.0, 2.0, 0.0},
		{0.0, 0.0, 2.0}
	};

	auto inv = diag3.inverse();
	if (!inv.has_value())
		throw std::runtime_error("inverse should exist");
	expect_matrix_equal(*inv, Matrix<double>{{0.5, 0.0, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.0, 0.5}}, "inverse");
}

static void test_singular_inverse()
{
	Matrix<double> singular{
		{1.0, 2.0},
		{2.0, 4.0}
	};

	if (singular.inverse().has_value())
		throw std::runtime_error("singular matrix should not be invertible");
}

int main()
{
	RUN_TEST(test_determinant);
	RUN_TEST(test_inverse);
	RUN_TEST(test_singular_inverse);
	return (EXIT_SUCCESS);
}
