#ifndef CPANJINLIAN_H
#define CPANJINLIAN_H

#ifndef CIKINDWOMEN_H
#include "IKindWomen.h"
#endif // CIKINDWOMEN_H

class CPanJinLian : public CIKindWomen
{
public:
    CPanJinLian();
    virtual ~CPanJinLian();
    virtual void MakeEyesWithMan();
    virtual void HappyWithMan();
};

#endif // CPANJINLIAN_H
