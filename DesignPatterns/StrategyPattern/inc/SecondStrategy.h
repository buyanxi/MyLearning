#ifndef CSECONDSTRATEGY_H
#define CSECONDSTRATEGY_H

#ifndef CISTRATEGY_H
#include "IStrategy.h"
#endif // CISTRATEGY_H


class CSecondStrategy : public CIStrategy
{
public:
    CSecondStrategy();
    virtual ~CSecondStrategy();
    virtual void Operate();
};

#endif // CSECONDSTRATEGY_H
