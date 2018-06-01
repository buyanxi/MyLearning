#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ManagerConfigData.h"

using namespace std;

int main()
{
//    SDKConfigInfo sSDKConfigInfo;
//
//    int iRet = CManagerConfigFileIF::GetInstance().ReadSDKConfigInfo(&sSDKConfigInfo);
//
//
//    sSDKConfigInfo.iCarDesignType = 1;
//    sSDKConfigInfo.iDriverPos = 1;
//    sSDKConfigInfo.iCameraType = 1;
//    sSDKConfigInfo.iImageType = 1;
//    sSDKConfigInfo.iImageMode = 1;
//    sSDKConfigInfo.iScreenType = 1;
//
//    int iRet1 = CManagerConfigFileIF::GetInstance().WriteSDKConfigInfo(&sSDKConfigInfo);

    CManagerConfigData::GetInstance().Init();

    DriverPosInfo eDriverPosInfo;
    CManagerConfigData::GetInstance().GetDriverPosInfo(eDriverPosInfo);

    CameraTypeInfo eCameraTypeInfo;
    CManagerConfigData::GetInstance().GetCameraTypeInfo(eCameraTypeInfo);


    eDriverPosInfo = DRIVER_POS_LEFT;
    CManagerConfigFileIF::GetInstance().WriteDriverPosInfo(&eDriverPosInfo);

    DriverPosInfo eDriverPosInfo1;
    CManagerConfigData::GetInstance().GetDriverPosInfo(eDriverPosInfo1);

    eCameraTypeInfo = CAMERA_640_480;
    CManagerConfigFileIF::GetInstance().WriteCameraTypeInfo(&eCameraTypeInfo);

    CameraTypeInfo eCameraTypeInfo1;
    CManagerConfigData::GetInstance().GetCameraTypeInfo(eCameraTypeInfo1);


    CManagerConfigData::GetInstance().DeInit();

    return 0;
}
