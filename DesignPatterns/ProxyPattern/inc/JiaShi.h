#ifndef CJIASHI_H
#define CJIASHI_H

#ifndef CIKINDWOMEN_H
#include "IKindWomen.h"
#endif // CIKINDWOMEN_H


class CJiaShi : public CIKindWomen
{
public:
    CJiaShi();
    virtual ~CJiaShi();
    virtual void MakeEyesWithMan();
    virtual void HappyWithMan();
};

#endif // CJIASHI_H
