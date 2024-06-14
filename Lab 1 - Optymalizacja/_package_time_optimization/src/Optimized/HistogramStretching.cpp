#include "pch.h"
#include "framework.h"

#include "HistogramStretching.h"

// 1. zamiana kolejnosci wykonywania petli, optymalizacja dostepu do cache
// improved 548 -> 348 about 40%

// 2. to samo co w 1.
// improved 348 -> 218 about 40%

// 3. to samo co w 1. i 2.
// improved 218 -> 73 about 60%

// 4. Zamiana int na short int, zmiejszenie rozmiaru zmiennej
// brak znacznych ulepszen

// 5. wyrzucenie obliczen stalych poza petle
// niewielka zmiana

// 6. eliminacja zbednych petli
// niewielka zmiana

// 7. zmiana nMin nMax na unsigned short
// improved 81 -> 47 about 50%

// 8. eliminacja dzielenia
// improved 47 -> 42 about 10%

// 9. rozszczepienie petli
// niewielka zmiana

// 10. early return
// niewielka zmiana

// 11. eliminacja zmiennej
// brak zmian

// 12. tablicowanie
// improved 40 -> 23 about 50%

void CHistogramStretching::HistogramStretching(BYTE** pImage, int nW, int nH)
{
	//find minimal value
	//find maximal value
	unsigned short nMin = pImage[0][0];
	unsigned short nMax = pImage[0][0];
	for(unsigned short i = 0; i < nH; i++)
		for (unsigned short j = 0; j < nW; j++)
		{
			if (pImage[i][j] < nMin)
				nMin = pImage[i][j];

			if (pImage[i][j] > nMax)
				nMax = pImage[i][j];
		}

	float fScale = 100.0 / (nMax - nMin);//calculates scale

	if (nMax != nMin)
	{
		BYTE array[256];

		for (unsigned short i = 0; i < 256; i++)
			array[i] = (BYTE)((i - nMin) * fScale + 0.5);//rounds floating point number to integer

		for (unsigned short i = 0; i < nH; i++)
			for (unsigned short j = 0; j < nW; j++)
				pImage[i][j] = array[pImage[i][j]];

		return;
	}
	
	for (unsigned short i = 0; i < nH; i++)
		for (unsigned short j = 0; j < nW; j++)
			pImage[i][j] = 0;
}

/*
#include "pch.h"
#include "framework.h"

#include "HistogramStretching.h"



void CHistogramStretching::HistogramStretching(BYTE** pImage, int nW, int nH)
{
	//find minimal value
	int nMin = pImage[0][0];
	for(int j = 0; j < nW; j++)
		for(int i = 0; i < nH; i++)
			if(pImage[i][j] < nMin)
				nMin = pImage[i][j];

	//find maximal value
	int nMax = pImage[0][0];
	for(int j = 0; j < nW; j++)
		for(int i = 0; i < nH; i++)
			if(pImage[i][j] > nMax)
				nMax = pImage[i][j];

	//normalize the image values
	for(int j = 0; j < nW; j++)
		for(int i = 0; i < nH; i++)
		{
			if(nMax != nMin)
			{
				float fScale = (nMax - nMin)/100.0;//calculates scale
				float fVal = (pImage[i][j] - nMin)/fScale;//scales pixel value
				int nVal = (int)(fVal + 0.5);//rounds floating point number to integer

				//checks BYTE range (must be 0-255)
				if(nVal < 0)
					nVal = 0;
				if(nVal > 255)
					nVal = 255;

				pImage[i][j] = nVal;
			}
			else
				pImage[i][j] = 0;//if all pixel values are the same, the image is changed to black
		}

}
*/