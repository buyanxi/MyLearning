#ifndef CMANAGERCONFIGFILEIF_H
#define CMANAGERCONFIGFILEIF_H

#ifndef CXMLFILEMANAGEIF_H
#include "XMLFileManageIF.h"
#endif // CXMLFILEMANAGEIF_H


class CManagerConfigFileIF
{
public:
    static CManagerConfigFileIF &GetInstance()
	{
		static CManagerConfigFileIF m_cManagerConfigFileIF;
		return m_cManagerConfigFileIF;
	}

public:
    int ReadSDKConfigInfo(SDKConfigInfo *psSDKConfigInfo);
    int WriteSDKConfigInfo(SDKConfigInfo *psSDKConfigInfo);
    int WriteDriverPosInfo(DriverPosInfo sDriverPosInfo);
    int WriteCameraTypeInfo(CameraTypeInfo sCameraTypeInfo);

private:
    CManagerConfigFileIF();
	~CManagerConfigFileIF();
    void Init();
	void DeInit();

private:
    bool   m_bInitFlag;
    char*  m_pchXMLFilePath;
};

#endif // CMANAGERCONFIGFILEIF_H
