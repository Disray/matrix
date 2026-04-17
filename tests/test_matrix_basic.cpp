#include "test_common.hpp"

static void test_add_sub_scale()
{
	Matrix<float> m{{1.0f, 2.0f}, {3.0f, 4.0f}};
	Matrix<float> m1{{7.0f, 4.0f}, {-2.0f, 2.0f}};

	m.add(m1);
	expect_matrix_equal(m, Matrix<float>{{8.0f, 6.0f}, {1.0f, 6.0f}}, "matrix add");
	m.sub(m1);
	expect_matrix_equal(m, Matrix<float>{{1.0f, 2.0f}, {3.0f, 4.0f}}, "matrix sub");
	m.scl(2.0f);
	expect_matrix_equal(m, Matrix<float>{{2.0f, 4.0f}, {6.0f, 8.0f}}, "matrix scale");
}

static void test_trace_and_transpose()
{
	Matrix<double> u{{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
	expect_equal(u.trace(), 15.0, "trace");
	expect_matrix_equal(u.transpose(), Matrix<double>{{1.0, 4.0, 7.0}, {2.0, 5.0, 8.0}, {3.0, 6.0, 9.0}}, "transpose");
}

static void test_matrix_lerp()
{
	Matrix<float> a{{2.0f, 1.0f}, {3.0f, 4.0f}};
	Matrix<float> b{{20.0f, 10.0f}, {30.0f, 40.0f}};
	expect_matrix_equal(lerp(a, b, 0.5), Matrix<float>{{11.0f, 5.5f}, {16.5f, 22.0f}}, "matrix lerp");
}

int main()
{
	RUN_TEST(test_add_sub_scale);
	RUN_TEST(test_trace_and_transpose);
	RUN_TEST(test_matrix_lerp);
	return (EXIT_SUCCESS);
}
