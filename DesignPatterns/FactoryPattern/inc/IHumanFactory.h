#ifndef IHUMANFACTORY_H
#define IHUMANFACTORY_H

#include <string>

#ifndef IHUMAN_H
#include "IHuman.h"
#endif // IHUMAN_H


class IHumanFactory
{
public:
    IHumanFactory()
    {
        m_pcIHuman = NULL;
    }
    virtual ~IHumanFactory() {}

    virtual IHuman *CreatHuman() = 0;
    virtual void DeleteHuman() = 0;

protected:
    IHuman *m_pcIHuman;
};

#endif // IHUMANFACTORY_H
