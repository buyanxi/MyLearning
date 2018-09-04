#include "MaximunActivity.h"
#include <algorithm>

using namespace std;

CMaximunActivity::CMaximunActivity()
{
    m_iMaxActivityNum = 0;
}

CMaximunActivity::~CMaximunActivity()
{
    //dtor
}

int CMaximunActivity::GreedyAlgorithm(Activity &sActivity, int iNum)
{
    //sort(sActivity, sActivity + iNum, Compare);
}

int CMaximunActivity::GetCountResult()
{
    return m_iMaxActivityNum;
}

bool CMaximunActivity::Compare(Activity sActA, Activity sActB)
{
    return sActA.iEndTime < sActB.iEndTime;
}
