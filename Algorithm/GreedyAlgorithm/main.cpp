#include <iostream>
#include <math.h>
using namespace std;

//当前的钱库，面值以及对应数量
int single_money[7] = {1,2,5,10,20,50,100};
int number_money[7] = {2,5,0,3,4,0,4};

//每种面值使用贪心算法后需要使用的张数
int count[7] = {};

int GreedyAlgorithm(int iMoney)
{
	if (iMoney >= 0) {
		for (int i = 6; i >= 0; i--) {
			count[i] = min(number_money[i], iMoney/single_money[i]);
			iMoney = iMoney - count[i]*single_money[i];
		}

		return 0;
	}
	else {
		return iMoney;
	}

}


int main()
{
	int iMoney;
	cout<<"Please input the amount of money:";
	cin>>iMoney;

	if(! GreedyAlgorithm(iMoney)) {
		cout<<"The resoult of greedy algorithm is that："<<endl;
		cout<<"100 RMB： "<<count[6]<<endl;
		cout<<"50 RMB： "<<count[5]<<endl;
		cout<<"20 RMB： "<<count[4]<<endl;
		cout<<"10 RMB： "<<count[3]<<endl;
		cout<<"5 RMB： "<<count[2]<<endl;
		cout<<"2 RMB： "<<count[1]<<endl;
		cout<<"1 RMB： "<<count[0]<<endl;
	}
	else {
		cout<<"Ops, Wrong number~"<<endl;
	}

	while (1) {}
	//system("pause");
	return 0;
}
