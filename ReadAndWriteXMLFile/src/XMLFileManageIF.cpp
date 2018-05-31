#include "XMLFileManageIF.h"
#include "tinyxml2.h"

using namespace tinyxml2;

CXMLFileManageIF::CXMLFileManageIF()
{
    //ctor
}

CXMLFileManageIF::~CXMLFileManageIF()
{
    //dtor
}

int CXMLFileManageIF::ReadSDKConfigInfoXML(char *pcXMLSDKConfigInfoPath, SDKConfigInfo *psSDKConfigInfo)
{
    if (NULL == pcXMLSDKConfigInfoPath || NULL == psSDKConfigInfo) {
		return 0;
	}

    XMLDocument xmlDoc;
    if (xmlDoc.LoadFile(pcXMLSDKConfigInfoPath))
	{
		printf("Read file: %s fail\n", pcXMLSDKConfigInfoPath);
		return 0;
	}

    XMLElement *xmlRootElement = xmlDoc.RootElement();
    XMLElement *xmlSubElement = xmlRootElement->FirstChildElement();

    int iLength = (sizeof(SDKConfigInfo)/sizeof(int));
    int *piData = new int[iLength];

    for (int i = 0; i < iLength; i++)
	{
		const char *pchElement = xmlSubElement->GetText();
		piData[i] = atoi(pchElement);
		xmlSubElement = xmlSubElement->NextSiblingElement();
	}

	psSDKConfigInfo->iCarDesignType = piData[0];
	psSDKConfigInfo->iDriverPos = piData[1];
	psSDKConfigInfo->iCameraType = piData[2];
	psSDKConfigInfo->iImageType = piData[3];
	psSDKConfigInfo->iImageMode = piData[4];
	psSDKConfigInfo->iScreenType = piData[5];

	if (NULL != piData) {
        delete []piData;
        piData = NULL;
    }

    return 1;
}

int CXMLFileManageIF::WriteSDKConfigInfoXML(char *pcXMLSDKConfigInfoPath, SDKConfigInfo *psSDKConfigInfo)
{
    if (NULL == pcXMLSDKConfigInfoPath || NULL == psSDKConfigInfo) {
        return 0;
    }

    XMLDocument xmlDoc;
	XMLElement *pRootElement = xmlDoc.NewElement("SDKConfigInfo");
	xmlDoc.InsertEndChild(pRootElement);

    char chInt2Char[128] = "";
    sprintf(chInt2Char, "%d",  psSDKConfigInfo->iCarDesignType);
    XMLElement* xmlSubElement = xmlDoc.NewElement( "iCarDesignType" );
    xmlSubElement->SetText(chInt2Char);
    pRootElement->InsertEndChild(xmlSubElement);

    sprintf(chInt2Char, "%d",  psSDKConfigInfo->iDriverPos);
    xmlSubElement = xmlDoc.NewElement( "iDriverPos" );
    xmlSubElement->SetText(chInt2Char);
    pRootElement->InsertEndChild(xmlSubElement);

    sprintf(chInt2Char, "%d",  psSDKConfigInfo->iCameraType);
    xmlSubElement = xmlDoc.NewElement( "iCameraType" );
    xmlSubElement->SetText(chInt2Char);
    pRootElement->InsertEndChild(xmlSubElement);

    sprintf(chInt2Char, "%d",  psSDKConfigInfo->iImageType);
    xmlSubElement = xmlDoc.NewElement( "iImageType" );
    xmlSubElement->SetText(chInt2Char);
    pRootElement->InsertEndChild(xmlSubElement);

    sprintf(chInt2Char, "%d",  psSDKConfigInfo->iImageMode);
    xmlSubElement = xmlDoc.NewElement("iImageMode");
    xmlSubElement->SetText(chInt2Char);
    pRootElement->InsertEndChild(xmlSubElement);

    sprintf(chInt2Char, "%d",  psSDKConfigInfo->iScreenType);
    xmlSubElement = xmlDoc.NewElement( "iScreenType" );
    xmlSubElement->SetText(chInt2Char);
    pRootElement->InsertEndChild(xmlSubElement);


	if (!xmlDoc.SaveFile(pcXMLSDKConfigInfoPath))
	{
		printf("Write file %s fail\n", pcXMLSDKConfigInfoPath);
	}

	//pRootElement->Clear();
	//xmlDoc.Clear();

    return 1;
}
