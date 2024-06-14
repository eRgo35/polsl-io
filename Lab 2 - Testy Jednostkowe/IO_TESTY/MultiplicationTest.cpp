#include "pch.h"

// Class of a test where you have to define a specific set of types of objects that you are going to use in a test.
class MultiplicationByIntTests : public ::testing::TestWithParam<tuple<Matrix, int, Matrix>> {
};


TEST_P(MultiplicationByIntTests, MultiplicationByInt)
{
	// Load the first param of make_tuple(...)
	Matrix A = get<0>(GetParam());

	// Load the second param of make_tuple(...)
	int multiplier = get<1>(GetParam());

	// Load the third param of make_tuple(...)
	Matrix expected_result = get<2>(GetParam());

	// Assuming that the input data is proper, this line asserts whether 'A * multiplier' executes without throwing an error. 
	// --------------- IMPORTANT ---------------
	// Analogously you can use ASSERT_ANY_THROW({...}) to test whether the code throws an error for a case with invalid input data, e.g. adding two matrices of different shapes. 
	// In such cases, if the code does throw an error, then the test is assumed to be passed as it is an expected behavior. Remember, throwing an error is not always a bad thing.
	ASSERT_NO_THROW({
		A * multiplier; 
		});

	Matrix C = A * multiplier;

	// Asserts whether the multiplication results in an expected value.
	// You can substitute ASSERT_TRUE(x == y) for ASSERT_EQ(x, y) in case you want more informative message in the test explorer window whenever a test fails. 
	// The stremaing syntax (<< operator) can be used right after any assertion to display a custom information in the message in case of failure of a test. You can use it the same way as standard cout <<.
	ASSERT_TRUE(C == expected_result) << "multiplier: " << multiplier;
}


// Initialization of parametric test cases. Each tuple represent a different test case with unique set of input parameters that will be used for every test defined using TEST_P and using the same test class.
// In this example, this set of cases will be used by the MultiplicationByInt test as they both share the same test class MultiplicationByIntTests.
INSTANTIATE_TEST_CASE_P(MultiplicationByIntTest, MultiplicationByIntTests,
	::testing::Values(
		make_tuple(Matrix(2, 1.0), 2, Matrix(2, 2.0)),
		make_tuple(Matrix(5,3, 1.0), 2, Matrix(5,3, 2.0)),
		make_tuple(Matrix(5, 1.0), 10, Matrix(5, 10.0)),
		make_tuple(Matrix(5, 1.0), 0, Matrix(5, 0.0)),
		make_tuple(Matrix(5, 1.0), -1, Matrix(5, -1.0)),
		make_tuple(Matrix(2, 1.0), 4, Matrix(2, 4.0)),
		make_tuple(Matrix(2, 2.0), 2, Matrix(2, 4.0)),
		make_tuple(Matrix(2, 3.0), 2, Matrix(2, 6.0))
	));




 /*
 ------------- TEMPLATE -------------
 You can use this template to create your own parametric tests. Just change the TEST_CLASS_NAME, TEST_NAME, TEST_INSTANCE_NAME to your own names.
 Also, please make sure to choose proper variable types in the class definition according to the values/objects you are going to pass in make_tuple(VAR1, VAR2, ...). Order does matter.



class TEST_CLASS_NAME : public ::testing::TestWithParam<tuple<TYPE1, TYPE2>> {};

TEST_P(TEST_CLASS_NAME, TEST_NAME)
{

}

INSTANTIATE_TEST_CASE_P(TEST_INSTANCE_NAME, TEST_CLASS_NAME,
	::testing::Values(
		make_tuple(VAR1, VAR2, ...)
	));

*/









