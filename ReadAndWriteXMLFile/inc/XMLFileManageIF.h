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

typedef struct _Camera_Rotate_Matrix
{
    float Rotate_Matrix0;
    float Rotate_Matrix1;
    float Rotate_Matrix2;
}CamRotateMatrix;

typedef struct _Camera_Trans_Matrix
{
    float Trans_Matrix0;
    float Trans_Matrix1;
    float Trans_Matrix2;
}CamTransMatrix;

typedef struct _Camera_Vanish_Point
{
    float Vanish_Point_X;
    float Vanish_Point_Y;
}CamVanishPoint;

typedef struct _Camera_External_Parameters
{
    CamRotateMatrix  sRotateMatrix;
    CamTransMatrix   sTransMatrix;
    CamVanishPoint   sVanishPoint;

}CamExternalParas;


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

    int ReadCamExternalParasInfoXML(char *pcXMLCamExternalParasPath, CamExternalParas *psCamExternalParas);
    int WriteCamExternalParasInfoXML(char *pcXMLCamExternalParasPath, CamExternalParas *psCamExternalParas);

private:
};

#endif // CXMLFILEMANAGEIF_H
