#ifndef CWANGPO_H
#define CWANGPO_H

#ifndef CIKINDWOMEN_H
#include "IKindWomen.h"
#endif // CIKINDWOMEN_H


typedef enum _Kind_Women
{
    PAN_JIN_LIAN = 0,
    JIA_SHI
}KindWomen;


class CWangPo : public CIKindWomen
{
public:
    CWangPo();
    virtual ~CWangPo();
    virtual void MakeEyesWithMan();
    virtual void HappyWithMan();

    void CreateIKindWomen(KindWomen eKindWomen);

private:
    CIKindWomen *m_pcKindWomen;
};

#endif // CWANGPO_H
