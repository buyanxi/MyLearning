#ifndef CXMLFILEMANAGEIF_H
#define CXMLFILEMANAGEIF_H

typedef struct _SDK_Config_Info
{
    int iCarDesignType;
    int iDriverPos;
    int iCameraType;
    int iImageType;
    int iImageMode;
    int iScreenType;
}SDKConfigInfo;

typedef enum _Driver_Pos_Info
{
    DRIVER_POS_LEFT = 0,
    DRIVER_POS_RIGHT
}DriverPosInfo;

typedef enum _Camera_Type_Info
{
    CAMERA_640_480 = 0,
    CAMERA_1280_720,
    CAMERA_1920_1080
}CameraTypeInfo;


class CXMLFileManageIF
{
public:
    static CXMLFileManageIF &GetInstance()
    {
        static CXMLFileManageIF m_cXMLFileManageIF;
        return m_cXMLFileManageIF;
    }

private:
    CXMLFileManageIF();
    virtual ~CXMLFileManageIF();

public:
    int ReadSDKConfigInfoXML(char *pcXMLSDKConfigInfoPath, SDKConfigInfo *psSDKConfigInfo);
    int WriteSDKConfigInfoXML(char *pcXMLSDKConfigInfoPath, SDKConfigInfo *psSDKConfigInfo);

private:
};

#endif // CXMLFILEMANAGEIF_H
