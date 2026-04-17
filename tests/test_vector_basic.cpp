#include "test_common.hpp"

static void test_add_sub_scale_float()
{
	Vector<float> u{2.5f, 3.5f};
	Vector<float> v = u;

	u.add(v);
	expect_vector_equal(u, Vector<float>{5.0f, 7.0f}, "vector addition");
	u.scl(2.0f);
	expect_vector_equal(u, Vector<float>{10.0f, 14.0f}, "vector scale");
	u.sub(Vector<float>{2.5f, 3.5f});
	expect_vector_equal(u, Vector<float>{7.5f, 10.5f}, "vector subtraction");
}

static void test_add_sub_scale_complex()
{
	Complex z1(10.0, 2.0);
	Complex z2(3.0, 4.0);
	Vector<Complex> c{z1, z2};
	Vector<Complex> c2{{0.0, -1.0}, {2.0, -5.0}};

	c.add(c2);
	expect_vector_equal(c, Vector<Complex>{{10.0, 1.0}, {5.0, -1.0}}, "complex add");
	c2.sub(c);
	expect_vector_equal(c2, Vector<Complex>{{-10.0, -2.0}, {-3.0, -4.0}}, "complex sub");
	c.scl({4.0, -3.0});
	expect_vector_equal(c, Vector<Complex>{{43.0, -26.0}, {17.0, -19.0}}, "complex scale");
}

static void test_linear_combination()
{
	Vector<double> e1({1.0, 0.0, 0.0});
	Vector<double> e2({0.0, 1.0, 0.0});
	Vector<double> e3({0.0, 0.0, 1.0});

	std::vector<Vector<double>> basis = {e1, e2, e3};
	std::vector<double> coefs = {10.0, -2.0, 0.5};

	expect_vector_equal(linear_combination(basis, coefs), Vector<double>{10.0, -2.0, 0.5}, "linear combination");
	expect_vector_equal(linear_combination({e1, e2}, {2.0, 3.0}), Vector<double>{2.0, 3.0, 0.0}, "linear combination overload");
}

int main()
{
	RUN_TEST(test_add_sub_scale_float);
	RUN_TEST(test_add_sub_scale_complex);
	RUN_TEST(test_linear_combination);
	return (EXIT_SUCCESS);
}
