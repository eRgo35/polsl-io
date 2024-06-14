#include "pch.h"

class MultiplicationMatrixTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {
};


TEST_P(MultiplicationMatrixTests, MultiplicationByMatrix)
{
	Matrix A = get<0>(GetParam());

	Matrix B = get<1>(GetParam());

	Matrix expected_result = get<2>(GetParam());

	ASSERT_NO_THROW({
		A * B;
		});

	Matrix C = A * B;

	ASSERT_TRUE(C == expected_result);
}

INSTANTIATE_TEST_CASE_P(MultiplicationMatrixTest, MultiplicationMatrixTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0), Matrix(2, 1.0), Matrix(2, 2.0)),
		make_tuple(Matrix(5, 3, 1.0), Matrix(2, 1.0), Matrix(5, 3, 2.0)),
		make_tuple(Matrix(5, 1.0), Matrix(2, 1.0), Matrix(5, 10.0)),
		make_tuple(Matrix(5, 1.0), Matrix(2, 1.0), Matrix(5, 0.0)),
		make_tuple(Matrix(5, 1.0), Matrix(2, 1.0), Matrix(5, -1.0)),
		make_tuple(Matrix(2, 1.0), Matrix(2, 1.0), Matrix(2, 4.0)),
		make_tuple(Matrix(2, 2.0), Matrix(2, 1.0), Matrix(2, 4.0)),
		make_tuple(Matrix(2, 3.0), Matrix(2, 1.0), Matrix(2, 6.0))
	));
