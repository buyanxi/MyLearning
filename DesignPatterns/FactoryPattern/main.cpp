#include <iostream>
#include "IHuman.h"
#include "YellowHuman.h"
#include "WhiteHuman.h"
#include "BlackHuman.h"
#include "IHumanFactory.h"
#include "YellowHumanFactory.h"
#include "WhiteHumanFactory.h"
#include "BlackHumanFactory.h"

using namespace std;

void DoFactoryMethodOne()
{
    cout << "The first factory method is that yellow human factory produces yellow human!" << endl;

    IHumanFactory *pcIHumanFactory = new CYellowHumanFactory;
    IHuman *pcIHuman = pcIHumanFactory->CreatHuman();
    pcIHuman->Cry();
    pcIHuman->Talk();
    pcIHuman->Laugh();

    pcIHumanFactory->DeleteHuman();

    if (NULL != pcIHumanFactory) {
        delete pcIHumanFactory;
        pcIHumanFactory = NULL;
    }

    cout << "-------------------------------------------------------------------------------" << endl;
}

void DoFactoryMethodTwo()
{
    cout << "The second factory method is that white human factory produces white human!" << endl;

    IHumanFactory *pcIHumanFactory = new CWhiteHumanFactory;
    IHuman *pcIHuman = pcIHumanFactory->CreatHuman();
    pcIHuman->Cry();
    pcIHuman->Talk();
    pcIHuman->Laugh();

    pcIHumanFactory->DeleteHuman();

    if (NULL != pcIHumanFactory) {
        delete pcIHumanFactory;
        pcIHumanFactory = NULL;
    }

    cout << "-------------------------------------------------------------------------------" << endl;
}

void DoFactoryMethodThird()
{
    cout << "The third factory method is that black human factory produces black human!" << endl;

    IHumanFactory *pcIHumanFactory = new CBlackHumanFactory;
    IHuman *pcIHuman = pcIHumanFactory->CreatHuman();
    pcIHuman->Cry();
    pcIHuman->Talk();
    pcIHuman->Laugh();

    pcIHumanFactory->DeleteHuman();

    if (NULL != pcIHumanFactory) {
        delete pcIHumanFactory;
        pcIHumanFactory = NULL;
    }
}

int main()
{
    DoFactoryMethodOne();
    DoFactoryMethodTwo();
    DoFactoryMethodThird();

    while(1) {
    }
    return 0;
}
