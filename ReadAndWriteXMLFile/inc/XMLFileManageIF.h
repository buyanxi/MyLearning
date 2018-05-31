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
