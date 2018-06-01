#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ManagerConfigData.h"

using namespace std;

int main()
{
    CManagerConfigData::GetInstance().Init();

    DriverPosInfo eDriverPosInfo;
    CManagerConfigData::GetInstance().GetDriverPosInfo(eDriverPosInfo);

    CameraTypeInfo eCameraTypeInfo;
    CManagerConfigData::GetInstance().GetCameraTypeInfo(eCameraTypeInfo);


    eDriverPosInfo = DRIVER_POS_LEFT;
    CManagerConfigFileIF::GetInstance().WriteDriverPosInfo(eDriverPosInfo);

    DriverPosInfo eDriverPosInfo1;
    CManagerConfigData::GetInstance().GetDriverPosInfo(eDriverPosInfo1);

    eCameraTypeInfo = CAMERA_640_480;
    CManagerConfigFileIF::GetInstance().WriteCameraTypeInfo(eCameraTypeInfo);

    CameraTypeInfo eCameraTypeInfo1;
    CManagerConfigData::GetInstance().GetCameraTypeInfo(eCameraTypeInfo1);


    CManagerConfigData::GetInstance().DeInit();

    return 0;
}
