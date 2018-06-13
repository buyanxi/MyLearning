#ifndef CYELLOWHUMANFACTORY_H
#define CYELLOWHUMANFACTORY_H

#ifndef IHUMANFACTORY_H
#include "IHumanFactory.h"
#endif // IHUMANFACTORY_H


class CYellowHumanFactory : public IHumanFactory
{
public:
    CYellowHumanFactory();
    virtual ~CYellowHumanFactory();

    virtual IHuman *CreatHuman();
    virtual void DeleteHuman();
};

#endif // CYELLOWHUMANFACTORY_H
