#include "pch.h"

class CopyTests : public ::testing::TestWithParam<tuple<Matrix, Matrix>> {};

TEST_P(CopyTests, CopyConstructor)
{
	Matrix original = get<0>(GetParam());
	Matrix expected = get<1>(GetParam());

	Matrix matrix(original);

	ASSERT_TRUE(matrix == expected);
}

INSTANTIATE_TEST_CASE_P(CopyTest, CopyTests,
	::testing::Values(
		make_tuple(Matrix(3, 1.0), Matrix(3, 1.0)),
		make_tuple(Matrix(3, -1.0), Matrix(3, -1.0)),
		make_tuple(Matrix(3, [](int i, int j) { return (double)i; }), Matrix(3, [](int i, int j) { return (double)i; }))
	));