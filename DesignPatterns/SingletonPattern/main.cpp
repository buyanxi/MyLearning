#include <iostream>
#include "Singleton.h"

using namespace std;

int main()
{
    CSingleton* singleton1 = CSingleton::GetInstance();
	CSingleton* singleton2 = CSingleton::GetInstance();

	if (singleton1 == singleton2) {
        cout << "singleton1 = singleton2" << endl;
	}

	cout<<CSingleton::GetInstance()->Operate()<<endl;
	cout<<CSingleton::GetInstance()->Operate()<<endl;


	cout<<CSingleton::_GetInstance().Operate()<<endl;
	cout<<CSingleton::_GetInstance().Operate()<<endl;


    while (1) {}
    return 0;
}
