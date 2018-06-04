#ifndef CFIRSTSTRATEGY_H
#define CFIRSTSTRATEGY_H

#ifndef CISTRATEGY_H
#include "IStrategy.h"
#endif // CISTRATEGY_H


class CFirstStrategy : public CIStrategy
{
public:
    CFirstStrategy();
    virtual ~CFirstStrategy();
    virtual void Operate();
};

#endif // CFIRSTSTRATEGY_H
