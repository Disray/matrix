#include "test_common.hpp"

static void test_dot_product()
{
	Vector<float> u1({1.0f, 1.0f});
	Vector<float> v1({1.0f, 1.0f});
	expect_equal(u1.dot(v1), 2.0f, "dot product float");

	Vector<Complex> u2({{0.0, 1.0}, {2.0, -1.0}});
	Vector<Complex> v2({{2.0, 3.0}, {1.0, -5.0}});
	expect_equal(u2.dot(v2), Complex(10.0, 11.0), "dot product complex");
}

static void test_norms()
{
	Vector<double> u({-1.0, -2.0});
	expect_equal(u.norm_1(), 3.0, "norm_1");
	expect_equal(u.norm(), std::sqrt(5.0), "norm_2");
	expect_equal(u.norm_inf(), 2.0, "norm_inf");
}

static void test_angle_cos()
{
	Vector<double> u({1.0, 0.0});
	Vector<double> v({0.0, 1.0});
	expect_equal(angle_cos(u, v), 0.0, "angle cosine");
}

static void test_cross_product()
{
	Vector<double> a({1.0, 2.0, 3.0});
	Vector<double> b({4.0, 5.0, 6.0});
	expect_vector_equal(cross_product(a, b), Vector<double>{-3.0, 6.0, -3.0}, "cross product");
}

static void test_vector_lerp()
{
	Vector<float> u({2.0f, 1.0f});
	Vector<float> v({4.0f, 2.0f});
	expect_vector_equal(lerp(u, v, 0.3), Vector<float>{2.6f, 1.3f}, "vector lerp");
}

int main()
{
	RUN_TEST(test_dot_product);
	RUN_TEST(test_norms);
	RUN_TEST(test_angle_cos);
	RUN_TEST(test_cross_product);
	RUN_TEST(test_vector_lerp);
	return (EXIT_SUCCESS);
}
