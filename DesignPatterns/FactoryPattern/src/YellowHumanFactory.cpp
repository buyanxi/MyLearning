#include "YellowHumanFactory.h"
#include "YellowHuman.h"

CYellowHumanFactory::CYellowHumanFactory()
{
}

CYellowHumanFactory::~CYellowHumanFactory()
{
    //dtor
}

IHuman * CYellowHumanFactory::CreatHuman()
{
    if (NULL == m_pcIHuman) {
        m_pcIHuman = new CYellowHuman;
    }

    return m_pcIHuman;
}

void CYellowHumanFactory::DeleteHuman()
{
    if (NULL != m_pcIHuman) {
        delete m_pcIHuman;
        m_pcIHuman = NULL;
    }
}
