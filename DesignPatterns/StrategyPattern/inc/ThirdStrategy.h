#ifndef CTHIRDSTRATEGY_H
#define CTHIRDSTRATEGY_H

#ifndef CISTRATEGY_H
#include "IStrategy.h"
#endif // CISTRATEGY_H


class CThirdStrategy : public CIStrategy
{
public:
    CThirdStrategy();
    virtual ~CThirdStrategy();
    virtual void Operate();
};

#endif // CTHIRDSTRATEGY_H
