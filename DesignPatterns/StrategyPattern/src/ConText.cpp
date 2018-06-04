#include <string.h>
#include "ConText.h"
#include "FirstStrategy.h"
#include "SecondStrategy.h"
#include "ThirdStrategy.h"

CConText::CConText()
{
    m_pcIStrategy = NULL;
}

CConText::~CConText()
{
    //dtor
}

void CConText::CreateIStrategy(BrocadeBag eBrocadeBag)
{
    if (FIRST_BROCADE_BAG == eBrocadeBag) {
        if (NULL == m_pcIStrategy)
            m_pcIStrategy = new CFirstStrategy;
    }
    else if (SECOND_BROCADE_BAG == eBrocadeBag) {
        if (NULL == m_pcIStrategy)
            m_pcIStrategy = new CSecondStrategy;
    }
    else if(THIRD_BROCADE_BAG == eBrocadeBag) {
        if (NULL == m_pcIStrategy)
            m_pcIStrategy = new CThirdStrategy;
    }
    else {

    }
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
