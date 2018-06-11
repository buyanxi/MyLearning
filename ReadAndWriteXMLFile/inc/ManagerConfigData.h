#ifndef CMANAGERCONFIGDATA_H
#define CMANAGERCONFIGDATA_H

#ifndef CMANAGERCONFIGFILEIF_H
#include "ManagerConfigFileIF.h"
#endif // CMANAGERCONFIGFILEIF_H


class CManagerConfigData
{
public:
    static CManagerConfigData &GetInstance()
    {
        static CManagerConfigData m_cManagerConfigData;
        return m_cManagerConfigData;
    }

public:
    void Init();
    void DeInit();

    int GetDriverPosInfo(DriverPosInfo& eDriverPosInfo);
    int GetCameraTypeInfo(CameraTypeInfo& eCameraTypeInfo);
    int GetCameraRotateMatrix(CamRotateMatrix& sCamRotateMatrix);
    int GetCameraTranslationMatrix(CamTransMatrix& sCamTransMatrix);
    int GetCameraVanishPoint(CamVanishPoint& sCamVanishPoint);

    int ReLoadSDKConfigInfo();
    int ReLoadCamExternalParasInfo();

private:
    CManagerConfigData();
    virtual ~CManagerConfigData();


private:
    bool                m_bInitFlag;
    bool                m_bResourceXMLReadFlag;
    SDKConfigInfo       m_sSDKConfigInfo;
    DriverPosInfo       m_eDriverPosInfo;
    CameraTypeInfo      m_eCameraTypeInfo;
    CamExternalParas    m_sCamExternalParasInfo;

};

#endif // CMANAGERCONFIGDATA_H
