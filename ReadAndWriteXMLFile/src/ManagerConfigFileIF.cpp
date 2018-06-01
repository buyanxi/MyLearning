#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ManagerConfigFileIF.h"
#include "ManagerConfigData.h"

CManagerConfigFileIF::CManagerConfigFileIF()
{
    m_bInitFlag = false;
    m_pchXMLFilePath = NULL;

    Init();
}

CManagerConfigFileIF::~CManagerConfigFileIF()
{
    DeInit();
}

void CManagerConfigFileIF::Init()
{
    if (m_bInitFlag) {
        return;
    }

    if (NULL == m_pchXMLFilePath) {
        m_pchXMLFilePath = new char[256];
    }

    char *pchWorkPath;
    if ((pchWorkPath = getcwd(NULL, 0)) == NULL) {
        printf("Get current work path failed!\n");
    }

    strcpy(m_pchXMLFilePath, pchWorkPath);
    strcat(m_pchXMLFilePath, "/Resource/XML/");

    m_bInitFlag = true;
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
    if (NULL == psSDKConfigInfo || NULL == m_pchXMLFilePath) {
        return 0;
    }

    if (!m_bInitFlag) {
        Init();
    }

    char chSDKConfigInfoPath[256];
    strcpy(chSDKConfigInfoPath, m_pchXMLFilePath);
    strcat(chSDKConfigInfoPath, "SDKConfigInfo.xml");

    return CXMLFileManageIF::GetInstance().ReadSDKConfigInfoXML(chSDKConfigInfoPath, psSDKConfigInfo);
}

int CManagerConfigFileIF::WriteSDKConfigInfo(SDKConfigInfo *psSDKConfigInfo)
{
    if (NULL == psSDKConfigInfo || NULL == m_pchXMLFilePath) {
        return 0;
    }

    if (!m_bInitFlag) {
        Init();
    }

    char chSDKConfigInfoPath[256];
    strcpy(chSDKConfigInfoPath, m_pchXMLFilePath);
    strcat(chSDKConfigInfoPath, "SDKConfigInfo.xml");

    return CXMLFileManageIF::GetInstance().WriteSDKConfigInfoXML(chSDKConfigInfoPath, psSDKConfigInfo);
}

int CManagerConfigFileIF::WriteDriverPosInfo(DriverPosInfo sDriverPosInfo)
{
    if (!m_bInitFlag) {
        Init();
    }

    SDKConfigInfo sSDKConfigInfo;
    if (!ReadSDKConfigInfo(&sSDKConfigInfo)) {
        return 0;
    }

    if (DRIVER_POS_LEFT == sDriverPosInfo) {
        sSDKConfigInfo.iDriverPos = 0;
    }
    else if (DRIVER_POS_RIGHT == sDriverPosInfo) {
        sSDKConfigInfo.iDriverPos = 1;
    }
    else {
        return 0;
    }

    int iRet1 = WriteSDKConfigInfo(&sSDKConfigInfo);
    int iRet2 = CManagerConfigData::GetInstance().ReLoadSDKConfigInfo();

    return iRet1 & iRet2;
}

int CManagerConfigFileIF::WriteCameraTypeInfo(CameraTypeInfo sCameraTypeInfo)
{
    if (!m_bInitFlag) {
        Init();
    }

    SDKConfigInfo sSDKConfigInfo;
    if (!ReadSDKConfigInfo(&sSDKConfigInfo)) {
        return 0;
    }

    if (CAMERA_640_480 == sCameraTypeInfo) {
        sSDKConfigInfo.iCameraType = 0;
    }
    else if (CAMERA_1280_720 == sCameraTypeInfo) {
        sSDKConfigInfo.iCameraType = 1;
    }
    else if (CAMERA_1920_1080 == sCameraTypeInfo) {
        sSDKConfigInfo.iCameraType = 2;
    }
    else {
        return 0;
    }

    int iRet1 = WriteSDKConfigInfo(&sSDKConfigInfo);
    int iRet2 = CManagerConfigData::GetInstance().ReLoadSDKConfigInfo();

    return iRet1 & iRet2;
}
