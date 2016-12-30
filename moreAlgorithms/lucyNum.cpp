#include <iostream>
#include <vector>
using namespace std;

int f(int x){
	int addNum = 0;
	while(x>9){
		addNum += x%10;
		x = x/10;
	}
	addNum += x;
	return addNum;
}

int g(int x){
	int addNum = 0;
	while((x/2)!=0){
		addNum += x%2;
		x = x/2;
	}
	addNum += x;
	return addNum;
}

int main(){
	int count;
	cin >> count;
	vector<int> x;
	vector<int> xLuckyNum;
	for (int i = 0; i<count; ++i){
		int tmp = 0;
		cin >> tmp;
		x.push_back(tmp);
		xLuckyNum.push_back(0);
	}
	for (int i=0; i<count; ++i){
		for (int j=2; j<=x[i]; ++j){
			if (f(j)<14){
				if (f(j) == g(j)){
					xLuckyNum[i] += 1;
					cout<<j<<endl;
				}
			}
		}
		cout<<xLuckyNum[i]+1<<endl;
	}
	system("pause");
	return 0;
}