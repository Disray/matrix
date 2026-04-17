#include "test_common.hpp"

static void test_matrix_vector_product()
{
	Matrix<double> u{{2.0, 0.0}, {0.0, 2.0}};
	Vector<double> v{{4.0, 2.0}};
	expect_vector_equal(u.mul_vec(v), Vector<double>{8.0, 4.0}, "matrix-vector product");
}

static void test_matrix_matrix_product()
{
	Matrix<double> u{{3.0, -5.0}, {6.0, 8.0}};
	Matrix<double> v{{2.0, 1.0}, {4.0, 2.0}};
	expect_matrix_equal(u.mul_mat(v), Matrix<double>{{-14.0, -7.0}, {44.0, 22.0}}, "matrix-matrix product");
}

static void test_projection_matrix()
{
	Matrix<float> proj = projection(1.0f, 16.0f / 9.0f, 0.1f, 100.0f);

	expect_equal(proj.getRows(), static_cast<size_t>(4), "projection rows");
	expect_equal(proj.getCols(), static_cast<size_t>(4), "projection cols");
	expect_equal(proj(3, 2), -1.0f, "projection sentinel");
}

int main()
{
	RUN_TEST(test_matrix_vector_product);
	RUN_TEST(test_matrix_matrix_product);
	RUN_TEST(test_projection_matrix);
	return (EXIT_SUCCESS);
}
