#ifndef CWHITEHUMANFACTORY_H
#define CWHITEHUMANFACTORY_H

#ifndef IHUMANFACTORY_H
#include "IHumanFactory.h"
#endif // IHUMANFACTORY_H


class CWhiteHumanFactory : public IHumanFactory
{
public:
    CWhiteHumanFactory();
    virtual ~CWhiteHumanFactory();

    virtual IHuman *CreatHuman();
    virtual void DeleteHuman();
};

#endif // CWHITEHUMANFACTORY_H
