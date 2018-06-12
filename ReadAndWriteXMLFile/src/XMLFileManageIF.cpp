#include "tinyxml2.h"
#include "XMLFileManageIF.h"


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
		xmlDoc.Clear();
	}

	xmlDoc.Clear();

    return 1;
}

int CXMLFileManageIF::ReadCamExternalParasInfoXML(char *pcXMLCamExternalParasPath, CamExternalParas *psCamExternalParas)
{
    if (NULL == pcXMLCamExternalParasPath || NULL == psCamExternalParas) {
		return 0;
	}

    XMLDocument xmlDoc;
    if (xmlDoc.LoadFile(pcXMLCamExternalParasPath))
	{
		printf("Read file: %s fail\n", pcXMLCamExternalParasPath);
		return 0;
	}

    XMLElement *xmlRootElement = xmlDoc.RootElement();
    XMLElement *xmlSubElement = xmlRootElement->FirstChildElement(); //rotate
    XMLElement *xmlSubElement_Next = xmlSubElement->NextSiblingElement(); //trans
    XMLElement *xmlSubElement_Next_Next = xmlSubElement_Next->NextSiblingElement(); //vanish point

    xmlSubElement = xmlSubElement->FirstChildElement();
    xmlSubElement_Next = xmlSubElement_Next->FirstChildElement();
    xmlSubElement_Next_Next = xmlSubElement_Next_Next->FirstChildElement();


    // Read Camera Rotate Matrix
    int iCamRotateMatrixLength = (sizeof(CamRotateMatrix)/sizeof(float));
    float *pfCamRotateMatrixData = new float[iCamRotateMatrixLength];
    for (int i = 0; i < iCamRotateMatrixLength; i++)
	{
		const char *pchElement = xmlSubElement->GetText();
		pfCamRotateMatrixData[i] = atof(pchElement);
		xmlSubElement = xmlSubElement->NextSiblingElement();
	}
	psCamExternalParas->sRotateMatrix.Rotate_Matrix0 = pfCamRotateMatrixData[0];
	psCamExternalParas->sRotateMatrix.Rotate_Matrix1 = pfCamRotateMatrixData[1];
	psCamExternalParas->sRotateMatrix.Rotate_Matrix2 = pfCamRotateMatrixData[2];
	if (NULL != pfCamRotateMatrixData) {
        delete []pfCamRotateMatrixData;
        pfCamRotateMatrixData = NULL;
    }

    // Read Camera Translation Matrix
    int iCamTransMatrixLength = (sizeof(CamTransMatrix)/sizeof(float));
    float *pfCamTransMatrixData = new float[iCamTransMatrixLength];
    for (int i = 0; i < iCamTransMatrixLength; i++)
	{
		const char *pchElement = xmlSubElement_Next->GetText();
		pfCamTransMatrixData[i] = atof(pchElement);
		xmlSubElement_Next = xmlSubElement_Next->NextSiblingElement();
	}
	psCamExternalParas->sTransMatrix.Trans_Matrix0 = pfCamTransMatrixData[0];
	psCamExternalParas->sTransMatrix.Trans_Matrix1 = pfCamTransMatrixData[1];
	psCamExternalParas->sTransMatrix.Trans_Matrix2 = pfCamTransMatrixData[2];
	if (NULL != pfCamTransMatrixData) {
        delete []pfCamTransMatrixData;
        pfCamTransMatrixData = NULL;
    }

    // Read Vanish Point Matrix
    int iCamVanishPointLength = (sizeof(CamVanishPoint)/sizeof(float));
    float *pfCamVanishPointData = new float[iCamVanishPointLength];
    for (int i = 0; i < iCamVanishPointLength; i++)
	{
		const char *pchElement = xmlSubElement_Next_Next->GetText();
		pfCamVanishPointData[i] = atof(pchElement);
		xmlSubElement_Next_Next = xmlSubElement_Next_Next->NextSiblingElement();
	}
	psCamExternalParas->sVanishPoint.Vanish_Point_X = pfCamVanishPointData[0];
	psCamExternalParas->sVanishPoint.Vanish_Point_Y = pfCamVanishPointData[1];
	if (NULL != pfCamVanishPointData) {
        delete []pfCamVanishPointData;
        pfCamVanishPointData = NULL;
    }

    return 1;
}

int CXMLFileManageIF::WriteCamExternalParasInfoXML(char *pcXMLCamExternalParasPath, CamExternalParas *psCamExternalParas)
{
    if (NULL == pcXMLCamExternalParasPath || NULL == psCamExternalParas) {
		return 0;
	}

    XMLDocument xmlDoc;
	XMLElement *pRootElement = xmlDoc.NewElement("Camara_External_Parameters");
	if (NULL == pRootElement)
    {
        xmlDoc.Clear();
        return 0;
    }
	xmlDoc.InsertEndChild(pRootElement);

	XMLElement *pRotateElement = xmlDoc.NewElement("Rotate_Matrix");
	if (NULL == pRotateElement)
    {
        xmlDoc.Clear();
        return 0;
    }
	pRootElement->InsertEndChild(pRotateElement);

	XMLElement *pTransElement = xmlDoc.NewElement("Trans_Matrix");
	if (NULL == pTransElement)
    {
        xmlDoc.Clear();
        return 0;
    }
	pRootElement->InsertEndChild(pTransElement);

	XMLElement *pVanishPointElement = xmlDoc.NewElement("Vanish_Point");
	if (NULL == pVanishPointElement)
    {
        xmlDoc.Clear();
        return 0;
    }
	pRootElement->InsertEndChild(pVanishPointElement);


	//Write Camera Rotate Matrix
    char chFloat2Char[128] = "";
    sprintf(chFloat2Char, "%f",  psCamExternalParas->sRotateMatrix.Rotate_Matrix0);
    XMLElement* xmlSubElement = xmlDoc.NewElement( "Rotate_Matrix0" );
    xmlSubElement->SetText(chFloat2Char);
    pRotateElement->InsertEndChild(xmlSubElement);

    sprintf(chFloat2Char, "%f",  psCamExternalParas->sRotateMatrix.Rotate_Matrix1);
    xmlSubElement = xmlDoc.NewElement( "Rotate_Matrix1" );
    xmlSubElement->SetText(chFloat2Char);
    pRotateElement->InsertEndChild(xmlSubElement);

    sprintf(chFloat2Char, "%f",  psCamExternalParas->sRotateMatrix.Rotate_Matrix2);
    xmlSubElement = xmlDoc.NewElement( "Rotate_Matrix2" );
    xmlSubElement->SetText(chFloat2Char);
    pRotateElement->InsertEndChild(xmlSubElement);

    //Write Camera Translation Matrix
    sprintf(chFloat2Char, "%f",  psCamExternalParas->sTransMatrix.Trans_Matrix0);
    xmlSubElement = xmlDoc.NewElement( "Trans_Matrix0" );
    xmlSubElement->SetText(chFloat2Char);
    pTransElement->InsertEndChild(xmlSubElement);

    sprintf(chFloat2Char, "%f",  psCamExternalParas->sTransMatrix.Trans_Matrix1);
    xmlSubElement = xmlDoc.NewElement( "Trans_Matrix1" );
    xmlSubElement->SetText(chFloat2Char);
    pTransElement->InsertEndChild(xmlSubElement);

    sprintf(chFloat2Char, "%f",  psCamExternalParas->sTransMatrix.Trans_Matrix2);
    xmlSubElement = xmlDoc.NewElement( "Trans_Matrix2" );
    xmlSubElement->SetText(chFloat2Char);
    pTransElement->InsertEndChild(xmlSubElement);

    //Write Vanish Point Matrix
    sprintf(chFloat2Char, "%f",  psCamExternalParas->sVanishPoint.Vanish_Point_X);
    xmlSubElement = xmlDoc.NewElement( "Vanish_Point_X" );
    xmlSubElement->SetText(chFloat2Char);
    pVanishPointElement->InsertEndChild(xmlSubElement);

    sprintf(chFloat2Char, "%f",  psCamExternalParas->sVanishPoint.Vanish_Point_Y);
    xmlSubElement = xmlDoc.NewElement( "Vanish_Point_Y" );
    xmlSubElement->SetText(chFloat2Char);
    pVanishPointElement->InsertEndChild(xmlSubElement);


    if (!xmlDoc.SaveFile(pcXMLCamExternalParasPath))
	{
		printf("Write file %s fail\n", pcXMLCamExternalParasPath);
		xmlDoc.Clear();
	}

    xmlDoc.Clear();

    return 1;
}
