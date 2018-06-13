#include "BlackHumanFactory.h"
#include "BlackHuman.h"

CBlackHumanFactory::CBlackHumanFactory()
{
}

CBlackHumanFactory::~CBlackHumanFactory()
{
    //dtor
}

IHuman *CBlackHumanFactory::CreatHuman()
{
    if (NULL == m_pcIHuman) {
        m_pcIHuman = new CBlackHuman;
    }

    return m_pcIHuman;
}

void CBlackHumanFactory::DeleteHuman()
{
    if (NULL != m_pcIHuman) {
        delete m_pcIHuman;
        m_pcIHuman = NULL;
    }
}
