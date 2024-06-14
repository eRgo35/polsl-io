#include "pch.h"
#include "framework.h"

#include "ImageFiltering.h"

const double four = 0.25;
const double eight = 0.125;
const double sixteen = 0.0625;

// 1. Zamiana kolejnosci petli
// improved 171 -> 87 about 60%

// 2. poprawa wewenetrzych petli miejscami
// nieznaczna roznica

// 3. eliminacja wewntrzych petli
// improved 87 -> 40 about 50%

// 4. eliminacja wywolan getindex

int GetIndex(int x, int y, int nW)
{
	return y*nW + x;
}

void CImageFiltering::ImageFiltering(BYTE* pInImg, int nW, int nH, BYTE* pOutImg)
{
	for(int j = 0; j < nH; j++)
		for(int i = 0; i < nW; i++)
			pOutImg[GetIndex(i, j, nW)] = 0;

	for(int j = 1; j < nH - 1; j++)
		for(int i = 1; i < nW - 1; i++)
		{
			double fSum = 0;

			int val = GetIndex(i, j, nW);

			fSum += pInImg[val - nW - 1] * sixteen;
			fSum += pInImg[val - nW] * eight;
			fSum += pInImg[val - nW + 1] * sixteen;

			fSum += pInImg[val - 1] * eight;
			fSum += pInImg[val] * four;
			fSum += pInImg[val + 1] * eight;

			fSum += pInImg[val + nW - 1] * sixteen;
			fSum += pInImg[val + nW] * eight;
			fSum += pInImg[val + nW + 1] * sixteen;

			pOutImg[val] = fSum;
		}
}

/*
#include "pch.h"
#include "framework.h"

#include "ImageFiltering.h"


int GetIndex(int x, int y, int nW)
{
	return y*nW + x;
}

void CImageFiltering::ImageFiltering(BYTE* pInImg, int nW, int nH, BYTE* pOutImg)
{
	for(int i = 0; i < nW; i++)
		for(int j = 0; j < nH; j++)
			pOutImg[GetIndex(i, j, nW)] = 0;

	for(int i = 1; i < nW - 1; i++)
		for(int j = 1; j < nH - 1; j++)
		{
			double fSum = 0;
			for(int m = -1; m <= 1; m++)
				for(int n = -1; n <= 1; n++)
				{
					fSum += pInImg[GetIndex(i + n, j + m, nW)] / 16.0;

					if(m == 0 || n == 0)
						fSum += pInImg[GetIndex(i + n, j + m, nW)] / 16.0;
					if(m == 0 && n == 0)
						fSum += 2*pInImg[GetIndex(i + n, j + m, nW)] / 16.0;
				}

			pOutImg[GetIndex(i, j, nW)] = fSum;
		}
}
*/