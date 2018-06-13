#ifndef CBLACKHUMANFACTORY_H
#define CBLACKHUMANFACTORY_H

#ifndef IHUMANFACTORY_H
#include "IHumanFactory.h"
#endif // IHUMANFACTORY_H


class CBlackHumanFactory : public IHumanFactory
{
public:
    CBlackHumanFactory();
    virtual ~CBlackHumanFactory();

    virtual IHuman *CreatHuman();
    virtual void DeleteHuman();
};

#endif // CBLACKHUMANFACTORY_H
