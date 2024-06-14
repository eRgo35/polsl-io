#include "pch.h"
#include "framework.h"

#include "MatrixMultiplication.h"


void CMatrixMultiplication::MatrixMultiplication(CMatrix& first, CMatrix& second, CMatrix& res)
{
	for(int i = 0; i < first.rows; i++)
		for(int j = 0; j < second.columns; j++)
		{
			double fRes = 0;
			for(int q = 0; q < first.columns; q++)			
				fRes += first.data[i][q] * second.data[q][j];			
			res.data[i][j] = fRes;
		}
}