#include "pch.h"

class DeterminantTests : public ::testing::TestWithParam<tuple<Matrix, double>> {};

TEST_P(DeterminantTests, ValidSize)
{
	Matrix A = get<0>(GetParam());
	double expected = get<1>(GetParam());

	bool isSquare = (A.columns == A.rows);

	if (A.columns == 0 || A.rows == 0) {
		ASSERT_ANY_THROW(A.determinant());
		return;
	}

	A.print();

	if (!isSquare) {
		ASSERT_ANY_THROW(A.determinant());
		return;
	}

	ASSERT_NO_THROW(A.determinant());
	ASSERT_TRUE(A.determinant() == expected);
}

TEST_P(DeterminantTests, Determinant)
{
	Matrix A = get<0>(GetParam());

	double expected = get<1>(GetParam());
	
	if (A.columns != A.rows) {
		ASSERT_ANY_THROW(A.determinant());
		return;
	}

	ASSERT_EQ(A.determinant(), expected);

}

INSTANTIATE_TEST_CASE_P(DeterminantTest, DeterminantTests,
	::testing::Values(
		make_tuple(Matrix(5, 0.0), 0),
		make_tuple(Matrix(7, 7, [](int i, int j) { return (double)i; }), 0),
		make_tuple(Matrix(4, 1, [](int i, int j) { return (double)i; }), 0),
		make_tuple(Matrix(0, [](int i, int j) { return (double)i; }), 0)
	));