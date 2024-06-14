#include "pch.h"

//TEST(Rank, RankEqualRows) {
//	int width = 5, height = 5;
//
//	// Matrix with 0's in the first row, 1's in the second row and so on initialized using function-based constructor.
//	Matrix A(height, width, [](int i, int j) {return (double)i; });
//
//	// Checks if the rank of a given matrix is equal to the epxected value of 1 (calculated beforehand). Basically it performs A.rank() == 1 operation and checks whether it evaluates to true.
//	// Using ASSERT_EQ over ASSERT_TRUE results in more informative message in the test explorer window whenever a test fails.
//	ASSERT_EQ(A.rank(), 1);
//}

class RankTests : public ::testing::TestWithParam<tuple<Matrix, int>> {
};

TEST_P(RankTests, RankEqualRows)
{
	Matrix A = get<0>(GetParam());

	int rank = get<1>(GetParam());
	
	A.print();

	ASSERT_EQ(A.rank(), rank);
}

INSTANTIATE_TEST_CASE_P(RankTest, RankTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0), 1),
		make_tuple(Matrix(5, 5, [](int i, int j) {return (double)i; }), 2),
		make_tuple(Matrix(3, 3, [](int i, int j) {return (double)(i + j);  }), 2),
		make_tuple(Matrix(4, 1, 4.0), 1),
		make_tuple(Matrix(4, 2, 3.12), 1),
		make_tuple(Matrix(2, 2, -1.0), 1),
		make_tuple(Matrix(3, 3, [](int i, int j) {return (double)(3 - i - j);  }), 2)
	));
