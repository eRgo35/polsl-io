#include <iostream>
#include "Matrix.h"
using namespace std;

// An initializer function to be used in a constructor Matrix(int rows, int columns, double(*initializer_func)(int, int)). It calculates and stores the values for each cell independently based on its row and column indices.
double initializer(int i, int j)
{
	return i * 2.0 - j / 2.0;
}

/* 
!!! IMPORTANT !!!
TestingLab.cpp : This file contains the 'main' function that is invoked when executing the program (CTRL+F5).
This is a playground to see how the Matrix class behaves in certain situations. You do not need to use this file unless
you want to print print the Matrix, experiment with different constructors etc. Feel free to use it as you wish.
*/
int main()
{
	// Example of vector-based constructor Matrix(int rows, int columns, vector<double> data)
	Matrix A(2, 3, { 0., 1., 3., 2., 5., 1. }); 

	// Example of function-based constructor Matrix(int rows, int columns, double(*initializer_func)(int, int)). 
	// You can also use lambda expressions. Here's a synonymous example without a need of defining a new function:
	// Matrix B(3, 4, [](int i, int j) {return (double)(i * 2.0 - j / 2.0); });
	Matrix B(3, 4, initializer); 
	cout << "Matrix A:\n";
	A.print();
	cout << "Matrix B:\n";
	B.print();
	Matrix C = A * B;
	cout << "Multiplication result:\n";
	C.print();
	cout <<"Rows: " <<C.rows <<"\nColumns: " << C.columns << endl;
}
