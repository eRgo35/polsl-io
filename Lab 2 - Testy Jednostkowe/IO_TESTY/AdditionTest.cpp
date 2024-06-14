#include "pch.h"

class MatrixAdditionTests : public ::testing::TestWithParam<tuple<Matrix, Matrix, Matrix>> {};

TEST_P(MatrixAdditionTests, Addition)
{
	Matrix A = get<0>(GetParam());

	Matrix B = get<1>(GetParam());

	Matrix expected = get<2>(GetParam());

	ASSERT_NO_THROW({
		A + B;
		});

	Matrix C = A + B;

	C.print();

	ASSERT_TRUE(C == expected);
}

INSTANTIATE_TEST_CASE_P(MatrixAdditionTest, MatrixAdditionTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0), Matrix(2, 1.0), Matrix(2, 2.0)),
		make_tuple(Matrix(1, 12.0), Matrix(1, 23.0), Matrix(1, 35.0)),
		make_tuple(Matrix(2, 1, 1.0), Matrix(2, 1, 0.0), Matrix(2, 1, 1.0)),
		make_tuple(Matrix(5, 5, 100.0), Matrix(5, 5, -100.0), Matrix(5, 5, 0.0)),
		make_tuple(Matrix(1, 2, 1.0), Matrix(2, 1, 1.0), Matrix(2, 2.0)),
		make_tuple(Matrix(2, 1.0), Matrix(2, 1.0), Matrix(2, 2.0)),
		make_tuple(Matrix(2, 1.0), Matrix(2, 1.0), Matrix(2, 2.0)),
		make_tuple(Matrix(2, 1.0), Matrix(2, 1.0), Matrix(2, 2.0)),
		make_tuple(Matrix(2, -1.0), Matrix(2, -1.0), Matrix(2, -2.0)),
		make_tuple(Matrix(1, -12.0), Matrix(1, 23.0), Matrix(1, 11.0)),
		make_tuple(Matrix(2, 1, 0.2), Matrix(2, 1, -0.1), Matrix(2, 1, 0.1))
	));