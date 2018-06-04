#ifndef CCONTEXT_H
#define CCONTEXT_H

#ifndef CISTRATEGY_H
#include "IStrategy.h"
#endif // CISTRATEGY_H

class CConText
{
public:
    CConText();
    virtual ~CConText();

    void NewIStrategy(CIStrategy *pcIStrategy);
    void DeleteIStrategy();
    void Operrate();

private:
    CIStrategy *m_pcIStrategy;
};

#endif // CCONTEXT_H
