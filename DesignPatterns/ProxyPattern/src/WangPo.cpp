#include <string.h>
#include "WangPo.h"
#include "JiaShi.h"
#include "PanJinLian.h"

CWangPo::CWangPo()
{
    m_pcKindWomen = NULL;
}

CWangPo::~CWangPo()
{
}

void CWangPo::MakeEyesWithMan()
{
    m_pcKindWomen->MakeEyesWithMan();
}

void CWangPo::HappyWithMan()
{
    m_pcKindWomen->HappyWithMan();
}

void CWangPo::CreateIKindWomen(KindWomen eKindWomen)
{
    if (m_pcKindWomen) {
        return;
    }

    if (PAN_JIN_LIAN == eKindWomen) {
        m_pcKindWomen = new CPanJinLian;
    }
    else if (JIA_SHI == eKindWomen) {
        m_pcKindWomen = new CJiaShi;
    }
    else {

    }
}

void CWangPo::DeleteIKindWomen()
{
    if (NULL != m_pcKindWomen) {
        delete m_pcKindWomen;
        m_pcKindWomen = NULL;
    }
}
