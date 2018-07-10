#ifndef CMINIMUMMONEY_H
#define CMINIMUMMONEY_H


class CMinimumMoney
{
public:
    CMinimumMoney();
    virtual ~CMinimumMoney();

public:
    int GreedyAlgorithm(int iMoney);
    int *GetCountResult();

private:
    int m_iCount[7];
};

#endif // CMINIMUMMONEY_H
