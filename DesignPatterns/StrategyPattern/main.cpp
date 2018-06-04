#include <iostream>
//#include "FirstStrategy.h"
//#include "SecondStrategy.h"
//#include "ThirdStrategy.h"
#include "ConText.h"

using namespace std;

int main()
{
    CConText cConText;

    cout<<"Just come to Wu Guo, opening the first brocade bag:"<<endl;
    cConText.CreateIStrategy(FIRST_BROCADE_BAG);
    cConText.Operrate();
    cConText.DeleteIStrategy();
    cout<<"_______________________________________________________________________________"<<endl;
    cout<<" "<<endl;

    cout<<"While Liu Bei was out of his mind, Opening the second brocade bag:"<<endl;
    cConText.CreateIStrategy(SECOND_BROCADE_BAG);
    cConText.Operrate();
    cConText.DeleteIStrategy();
    cout<<"_______________________________________________________________________________"<<endl;
    cout<<" "<<endl;

    cout<<"When the soldiers of Sun Quan were catching up, Opening the third brocade bag:"<<endl;
    cConText.CreateIStrategy(THIRD_BROCADE_BAG);
    cConText.Operrate();
    cConText.DeleteIStrategy();

    while(1) {}
    return 0;
}
