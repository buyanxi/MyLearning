#include <string.h>
#include "Singleton.h"

CSingleton::CSingleton()
{
}

CSingleton::~CSingleton()
{
    //dtor
}


CSingleton* CSingleton::m_pcSingleton = new CSingleton;
CSingleton* CSingleton::GetInstance()
{
    return m_pcSingleton;
}

int CSingleton::Operate()
{
    static int iCount = 1;
    ++iCount;
}
