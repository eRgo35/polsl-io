#include "pch.h"

class ConstructorTests : public ::testing::TestWithParam<tuple<Matrix, int, int, std::vector<double>>> {};

TEST_P(ConstructorTests, Inits)
{
	Matrix matrix = get<0>(GetParam());
	int rows = get<1>(GetParam());
	int cols = get<2>(GetParam());
	std::vector<double> expected = get<3>(GetParam());

	if (expected.size() != rows * cols)
		ASSERT_ANY_THROW({
			Matrix test(rows, cols, expected);
			});

	if (rows < 0 || cols < 0)
		ASSERT_ANY_THROW({
			Matrix test(rows, cols);
			});

	ASSERT_EQ(matrix.rows, rows);
	ASSERT_EQ(matrix.columns, cols);

	ASSERT_EQ(matrix.data, expected);
}

std::vector<double> zeros = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> zeros1 = { 0.0, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> inc = { 1.0, 2.0, 3.0, 4.0 };
std::vector<double> aa = { 1.0, 2.0, 3.0, 4.0, 0.1, -0.1 };
std::vector<double> ab = { -1.0, -2.0, -3.0, -4.0, 1.1, -0.1 };

INSTANTIATE_TEST_CASE_P(ConstructorTest, ConstructorTests,
	::testing::Values(
		make_tuple(Matrix(3, 0.0), 3, 3, zeros),
		make_tuple(Matrix(0, 0.0), 0, 0, std::vector<double>{}),
		make_tuple(Matrix(3, 3, 0.0), 3, 3, zeros),
		make_tuple(Matrix(1, 5, 0.0), 1, 5, zeros1),
		make_tuple(Matrix(-1, -5, 0.0), -1, -5, zeros1),
		make_tuple(Matrix(-3, 0.0), -3, -3, zeros),
		make_tuple(Matrix(2, inc), 2, 2, inc),
		make_tuple(Matrix(2, { -1.0, -2.0, -3.0, -4.0}), 2, 2, std::vector<double>{-1.0, -2.0, -3.0, -4.0}),
		make_tuple(Matrix(3, 2, aa), 3, 2, aa),
		make_tuple(Matrix(2, 4, ab), 2, 4, ab),
		make_tuple(Matrix(2, 4, aa), 2, 4, aa),
		make_tuple(Matrix(2, 2, ab), 2, 2, ab)
	));