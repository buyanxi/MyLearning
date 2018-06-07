#include <string.h>
#include "WangPo.h"

CWangPo::CWangPo()
{
    m_pcKindWomen = NULL;
}

CWangPo::~CWangPo()
{
    if (NULL != m_pcKindWomen) {
        delete m_pcKindWomen;
        m_pcKindWomen = NULL;
    }
}

void CWangPo::MakeEyesWithMan()
{

}

void CWangPo::HappyWithMan()
{

}

void CWangPo::CreateIKindWomen(KindWomen eKindWomen)
{
    if (m_pcKindWomen) {
        return;
    }

    if (PAN_JIN_LIAN == eKindWomen) {

    }
    else if (JIA_SHI == eKindWomen) {

    }
    else {

    }
}
