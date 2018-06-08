#include "Singleton.h"

CSingleton::CSingleton()
{
    m_cSingleton = NULL;
}

CSingleton::~CSingleton()
{
    //dtor
}


CSingleton* CSingleton::GetInstance()
{
    if (NULL == m_cSingleton)
}
