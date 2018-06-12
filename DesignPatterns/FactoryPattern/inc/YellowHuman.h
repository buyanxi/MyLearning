#ifndef CYELLOWHUMAN_H
#define CYELLOWHUMAN_H

#ifndef IHUMAN_H
#include "IHuman.h"
#endif // IHUMAN_H


class CYellowHuman : public IHuman
{
public:
    CYellowHuman();
    virtual ~CYellowHuman();

    virtual void Laugh();
    virtual void Cry();
    virtual void Talk();
};

#endif // CYELLOWHUMAN_H
