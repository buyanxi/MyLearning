#include <iostream>
#include "WangPo.h"
#include "JiaShi.h"
#include "PanJinLian.h"

using namespace std;

int main()
{
    CWangPo cWangPo;
    cWangPo.CreateIKindWomen(PAN_JIN_LIAN);
    cWangPo.MakeEyesWithMan();
    cWangPo.HappyWithMan();
    cWangPo.DeleteIKindWomen();
    cout<<"------------------------------------"<<endl;


    cWangPo.CreateIKindWomen(JIA_SHI);
    cWangPo.MakeEyesWithMan();
    cWangPo.HappyWithMan();
    cWangPo.DeleteIKindWomen();

    while(1) {}


    return 0;
}
