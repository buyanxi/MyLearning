#include <string.h>
#include "ConText.h"

CConText::CConText()
{
    m_pcIStrategy = NULL;
}

CConText::~CConText()
{
    //dtor
}

void CConText::NewIStrategy(CIStrategy *pcIStrategy)
{
    if(NULL == pcIStrategy) {
        return;
    }

    m_pcIStrategy = pcIStrategy;
}

void CConText::DeleteIStrategy()
{
    if (NULL != m_pcIStrategy) {
        delete m_pcIStrategy;
        m_pcIStrategy = NULL;
    }
}

void CConText::Operrate()
{
    if (NULL == m_pcIStrategy) {
        return;
    }

    m_pcIStrategy->Operate();
}
