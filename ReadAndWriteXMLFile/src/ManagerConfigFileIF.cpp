#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ManagerConfigFileIF.h"

CManagerConfigFileIF::CManagerConfigFileIF()
{
    m_pchXMLFilePath = NULL;

    Init();
}

CManagerConfigFileIF::~CManagerConfigFileIF()
{
    DeInit();
}

void CManagerConfigFileIF::Init()
{
    if (NULL == m_pchXMLFilePath) {
        m_pchXMLFilePath = new char[256];
    }

    char *pchWorkPath;
    if ((pchWorkPath = getcwd(NULL, 0)) == NULL) {
        printf("Get current work path failed!\n");
    }

    strcpy(m_pchXMLFilePath, pchWorkPath);
    strcat(m_pchXMLFilePath, "/Resource/XML/");
}

void CManagerConfigFileIF::DeInit()
{
    if (NULL != m_pchXMLFilePath) {
        delete []m_pchXMLFilePath;
        m_pchXMLFilePath = NULL;
    }
}

int CManagerConfigFileIF::ReadSDKConfigInfo(SDKConfigInfo *psSDKConfigInfo)
{
    if (NULL == psSDKConfigInfo) {
        return 0;
    }

    char chSDKConfigInfoPath[256];
    strcpy(chSDKConfigInfoPath, m_pchXMLFilePath);
    strcat(chSDKConfigInfoPath, "SDKConfigInfo.xml");

    return CXMLFileManageIF::GetInstance().ReadSDKConfigInfoXML(chSDKConfigInfoPath, psSDKConfigInfo);
}

int CManagerConfigFileIF::WriteSDKConfigInfo(SDKConfigInfo *psSDKConfigInfo)
{
    if (NULL == psSDKConfigInfo) {
        return 0;
    }

    char chSDKConfigInfoPath[256];
    strcpy(chSDKConfigInfoPath, m_pchXMLFilePath);
    strcat(chSDKConfigInfoPath, "SDKConfigInfo.xml");

    return CXMLFileManageIF::GetInstance().WriteSDKConfigInfoXML(chSDKConfigInfoPath, psSDKConfigInfo);
    return 1;
}
