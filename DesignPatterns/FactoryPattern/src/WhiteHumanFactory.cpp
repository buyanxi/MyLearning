#include "WhiteHumanFactory.h"
#include "WhiteHuman.h"

CWhiteHumanFactory::CWhiteHumanFactory()
{
}

CWhiteHumanFactory::~CWhiteHumanFactory()
{
    //dtor
}

IHuman *CWhiteHumanFactory::CreatHuman()
{
    if (NULL == m_pcIHuman) {
        m_pcIHuman = new CWhiteHuman;
    }

    return m_pcIHuman;
}

void CWhiteHumanFactory::DeleteHuman()
{
    if (NULL != m_pcIHuman) {
        delete m_pcIHuman;
        m_pcIHuman = NULL;
    }
}
