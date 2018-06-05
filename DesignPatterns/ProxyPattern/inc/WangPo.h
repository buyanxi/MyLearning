#ifndef CWANGPO_H
#define CWANGPO_H

#ifndef CIKINDWOMEN_H
#include "IKindWomen.h"
#endif // CIKINDWOMEN_H


class CWangPo : public CIKindWomen
{
public:
    CWangPo();
    virtual ~CWangPo();
    virtual void MakeEyesWithMan();
    virtual void HappyWithMan();

private:
    CIKindWomen *m_pKindWomen;
};

#endif // CWANGPO_H
