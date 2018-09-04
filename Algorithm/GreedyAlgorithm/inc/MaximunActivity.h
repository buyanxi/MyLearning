#ifndef CMAXIMUNACTIVITY_H
#define CMAXIMUNACTIVITY_H


typedef struct Act
{
    int iStartTime;
    int iEndTime;
}Activity;

class CMaximunActivity
{
public:
    CMaximunActivity();
    virtual ~CMaximunActivity();

public:
    int GreedyAlgorithm(Activity &sActivity, int iNum);
    int GetCountResult();

private:
    bool Compare(Activity sActA, Activity sActB);

private:
    int m_iMaxActivityNum;
};

#endif // CMAXIMUNACTIVITY_H
