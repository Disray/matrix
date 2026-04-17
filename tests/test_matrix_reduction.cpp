#include "test_common.hpp"

static void test_row_echelon()
{
	Matrix<double> u{
		{1.0, 2.0},
		{3.0, 4.0}
	};

	expect_matrix_equal(u.row_echelon(), Matrix<double>{{1.0, 0.0}, {0.0, 1.0}}, "row echelon");
}

static void test_rank()
{
	Matrix<double> u({
		{1.0, 2.0, 0.0, 0.0},
		{2.0, 4.0, 0.0, 0.0},
		{-1.0, 2.0, 1.0, 1.0}
	});

	expect_equal(u.rank(), static_cast<size_t>(2), "matrix rank");
}

int main()
{
	RUN_TEST(test_row_echelon);
	RUN_TEST(test_rank);
	return (EXIT_SUCCESS);
}
