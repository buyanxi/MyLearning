#ifndef CBLACKHUMAN_H
#define CBLACKHUMAN_H

#ifndef IHUMAN_H
#include "IHuman.h"
#endif // IHUMAN_H


class CBlackHuman : public IHuman
{
public:
    CBlackHuman();
    virtual ~CBlackHuman();

    virtual void Laugh();
    virtual void Cry();
    virtual void Talk();
};

#endif // CBLACKHUMAN_H
