#include <string.h>
#include "ManagerConfigData.h"

CManagerConfigData::CManagerConfigData()
{
    m_bInitFlag = false;
    m_bResourceXMLReadFlag = true;
    memset(&m_sSDKConfigInfo, 0 , sizeof(SDKConfigInfo));
    m_eDriverPosInfo = DRIVER_POS_LEFT;
    m_eCameraTypeInfo = CAMERA_640_480;
}

CManagerConfigData::~CManagerConfigData()
{
    //dtor
}

void CManagerConfigData::Init()
{
    if (m_bInitFlag) {
        return;
    }

    int iReadXMLNum = 0;
    int iReadResult = 0;

    int iSDKConfigInfoResult = CManagerConfigFileIF::GetInstance().ReadSDKConfigInfo(&m_sSDKConfigInfo);
    ++iReadXMLNum;
    iReadResult += iSDKConfigInfoResult;

    int iCamExternalParasInfoResult = CManagerConfigFileIF::GetInstance().ReadCamExternalParasInfo(&m_sCamExternalParasInfo);
    ++iReadXMLNum;
    iReadResult += iSDKConfigInfoResult;

    if (iReadResult == iReadXMLNum) {
        m_bResourceXMLReadFlag = true;
    }
    else {
        m_bResourceXMLReadFlag = false;
    }

    m_bInitFlag = true;
}

void CManagerConfigData::DeInit()
{
    m_bInitFlag = false;
}

int CManagerConfigData::GetDriverPosInfo(DriverPosInfo& eDriverPosInfo)
{
    if (!m_bInitFlag) {
        Init();
    }

    if (!m_bResourceXMLReadFlag) {
        return 0;
    }

    if (0 == m_sSDKConfigInfo.iDriverPos) {
        eDriverPosInfo = DRIVER_POS_LEFT;
    }
    else if (1 == m_sSDKConfigInfo.iDriverPos) {
        eDriverPosInfo = DRIVER_POS_RIGHT;
    }
    else {
        return 0;
    }

    return 1;
}

int CManagerConfigData::GetCameraTypeInfo(CameraTypeInfo& eCameraTypeInfo)
{
    if (!m_bInitFlag) {
        Init();
    }

    if (!m_bResourceXMLReadFlag) {
        return 0;
    }

    if (0 == m_sSDKConfigInfo.iCameraType) {
        eCameraTypeInfo = CAMERA_640_480;
    }
    else if (1 == m_sSDKConfigInfo.iCameraType) {
        eCameraTypeInfo = CAMERA_1280_720;
    }
    else if (2 == m_sSDKConfigInfo.iCameraType) {
        eCameraTypeInfo = CAMERA_1920_1080;
    }
    else {
        return 0;
    }

    return 1;
}

int CManagerConfigData::GetCameraRotateMatrix(CamRotateMatrix& sCamRotateMatrix)
{
    if (!m_bInitFlag) {
        Init();
    }

    if (!m_bResourceXMLReadFlag) {
        return 0;
    }

    sCamRotateMatrix.Rotate_Matrix0 = m_sCamExternalParasInfo.sRotateMatrix.Rotate_Matrix0;
    sCamRotateMatrix.Rotate_Matrix1 = m_sCamExternalParasInfo.sRotateMatrix.Rotate_Matrix1;
    sCamRotateMatrix.Rotate_Matrix2 = m_sCamExternalParasInfo.sRotateMatrix.Rotate_Matrix2;

    return 1;
}

int CManagerConfigData::GetCameraTranslationMatrix(CamTransMatrix& sCamTransMatrix)
{
    if (!m_bInitFlag) {
        Init();
    }

    if (!m_bResourceXMLReadFlag) {
        return 0;
    }

    sCamTransMatrix.Trans_Matrix0 = m_sCamExternalParasInfo.sTransMatrix.Trans_Matrix0;
    sCamTransMatrix.Trans_Matrix1 = m_sCamExternalParasInfo.sTransMatrix.Trans_Matrix1;
    sCamTransMatrix.Trans_Matrix2 = m_sCamExternalParasInfo.sTransMatrix.Trans_Matrix2;

    return 1;
}

int CManagerConfigData::GetCameraVanishPoint(CamVanishPoint& sCamVanishPoint)
{
    if (!m_bInitFlag) {
        Init();
    }

    if (!m_bResourceXMLReadFlag) {
        return 0;
    }

    sCamVanishPoint.Vanish_Point_X = m_sCamExternalParasInfo.sVanishPoint.Vanish_Point_X;
    sCamVanishPoint.Vanish_Point_Y = m_sCamExternalParasInfo.sVanishPoint.Vanish_Point_Y;

    return 1;
}

int CManagerConfigData::ReLoadSDKConfigInfo()
{
    if (!m_bInitFlag) {
        return 0;
    }

    return CManagerConfigFileIF::GetInstance().ReadSDKConfigInfo(&m_sSDKConfigInfo);
}

int CManagerConfigData::ReLoadCamExternalParasInfo()
{
    if (!m_bInitFlag) {
        return 0;
    }

    return CManagerConfigFileIF::GetInstance().ReadCamExternalParasInfo(&m_sCamExternalParasInfo);
}
