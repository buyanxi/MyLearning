#include <iostream>
#include "MinimumMoney.h"

using namespace std;

int main()
{
	int iMoney;
	cout<<"Please input the amount of money:";
	cin>>iMoney;

	CMinimumMoney cMinimumMoney;
	int iRet = cMinimumMoney.GreedyAlgorithm(iMoney);

	if (!iRet) {
        int *piCount = cMinimumMoney.GetCountResult();

        cout<<"The resoult of greedy algorithm is that："<<endl;
		cout<<"100 RMB： "<<piCount[6]<<endl;
		cout<<"50 RMB： "<<piCount[5]<<endl;
		cout<<"20 RMB： "<<piCount[4]<<endl;
		cout<<"10 RMB： "<<piCount[3]<<endl;
		cout<<"5 RMB： "<<piCount[2]<<endl;
		cout<<"2 RMB： "<<piCount[1]<<endl;
		cout<<"1 RMB： "<<piCount[0]<<endl;
	}
	else {
        cout<<"Ops, Wrong number~"<<endl;
	}



	while (1) {}
	//system("pause");
	return 0;
}
