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

    CamRotateMatrix sCamRotateMatrix;
    CManagerConfigData::GetInstance().GetCameraRotateMatrix(sCamRotateMatrix);

    CamTransMatrix sCamTransMatrix;
    CManagerConfigData::GetInstance().GetCameraTranslationMatrix(sCamTransMatrix);

    CamVanishPoint sCamVanishPoint;
    CManagerConfigData::GetInstance().GetCameraVanishPoint(sCamVanishPoint);

    sCamVanishPoint.Vanish_Point_X = 396.21;
    sCamVanishPoint.Vanish_Point_Y = 100.25;
    CManagerConfigFileIF::GetInstance().WriteCamVanishPointParasInfo(&sCamVanishPoint);
    CManagerConfigData::GetInstance().GetCameraVanishPoint(sCamVanishPoint);

    sCamRotateMatrix.Rotate_Matrix0 = 0.1254;
    sCamRotateMatrix.Rotate_Matrix1 = 0.1554;
    sCamRotateMatrix.Rotate_Matrix2 = 0.1754;

    sCamTransMatrix.Trans_Matrix0 = -124.53;
    sCamTransMatrix.Trans_Matrix1 = 356.1234;
    sCamTransMatrix.Trans_Matrix2 = 3214.852;
    CManagerConfigFileIF::GetInstance().WriteCamRotateAndTransParasInfo(&sCamRotateMatrix, &sCamTransMatrix);
    CManagerConfigData::GetInstance().GetCameraRotateMatrix(sCamRotateMatrix);
    CManagerConfigData::GetInstance().GetCameraTranslationMatrix(sCamTransMatrix);

    CManagerConfigData::GetInstance().DeInit();

    return 0;
}
