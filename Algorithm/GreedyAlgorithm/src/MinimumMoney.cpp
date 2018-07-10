#include <iostream>
#include <math.h>
#include "MinimumMoney.h"

using namespace std;

const int iSingleMoney[7] = {1,2,5,10,20,50,100};
const int iNumberMoney[7] = {2,5,0,3,4,0,4};

CMinimumMoney::CMinimumMoney()
{
    m_iCount[7] = {0};
}

CMinimumMoney::~CMinimumMoney()
{
    //dtor
}

int CMinimumMoney::GreedyAlgorithm(int iMoney)
{
    if (iMoney >= 0) {
		for (int i = 6; i >= 0; i--) {
			m_iCount[i] = min(iNumberMoney[i], iMoney/iSingleMoney[i]);
			iMoney = iMoney - m_iCount[i] * iSingleMoney[i];
		}

		return 0;
	}
	else {
		return iMoney;
	}
}

int *CMinimumMoney::GetCountResult()
{
    return m_iCount;
}

