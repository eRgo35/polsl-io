#include "pch.h"

class LoadDataTests : public ::testing::TestWithParam<tuple<Matrix, std::vector<double>, double, double, Matrix>> {};

TEST_P(LoadDataTests, LoadingToExisting)
{
	Matrix A = get<0>(GetParam());

	std::vector<double> data = get<1>(GetParam());

	double rows = get<2>(GetParam());
	double cols = get<3>(GetParam());

	Matrix expected = get<4>(GetParam());

	bool status = A.load_data(data, 3, 3);

	if (data.size() != rows * cols)
	{
		ASSERT_FALSE(status);
		return;
	}

	ASSERT_EQ(A.data, data);

}

std::vector<double> ba = { .1, .2, .3, .4, .5, .6, .7, .8, .9 };

INSTANTIATE_TEST_CASE_P(LoadDataTest, LoadDataTests,
	::testing::Values(
		make_tuple(Matrix(3, 3, 0.0), ba, 3, 3, Matrix(3, 3, ba)),
		make_tuple(Matrix(1, 2, 0.0), ba, 1, 2, Matrix(1, 2, ba)),
		make_tuple(Matrix(5, 5, 0.0), ba, 5, 5, Matrix(5, 5, ba))
	));