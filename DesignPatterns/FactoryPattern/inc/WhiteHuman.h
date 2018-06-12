#ifndef CWHITEHUMAN_H
#define CWHITEHUMAN_H

#ifndef IHUMAN_H
#include "IHuman.h"
#endif // IHUMAN_H


class CWhiteHuman : public IHuman
{
public:
    CWhiteHuman();
    virtual ~CWhiteHuman();

    virtual void Laugh();
    virtual void Cry();
    virtual void Talk();
};

#endif // CWHITEHUMAN_H
