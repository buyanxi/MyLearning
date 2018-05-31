#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ManagerConfigFileIF.h"

using namespace std;

int main()
{
    SDKConfigInfo sSDKConfigInfo;

    int iRet = CManagerConfigFileIF::GetInstance().ReadSDKConfigInfo(&sSDKConfigInfo);


    sSDKConfigInfo.iCarDesignType = 1;
    sSDKConfigInfo.iDriverPos = 1;
    sSDKConfigInfo.iCameraType = 1;
    sSDKConfigInfo.iImageType = 1;
    sSDKConfigInfo.iImageMode = 1;
    sSDKConfigInfo.iScreenType = 1;

    int iRet1 = CManagerConfigFileIF::GetInstance().WriteSDKConfigInfo(&sSDKConfigInfo);

    return 0;
}
