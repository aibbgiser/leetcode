#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
	int res = -1;
	while( true ){
		int tmpRes = -1;
		int user = -1;
		cout<<"please choose: 0-scissor, 1-rock, 2-paper.";
		cin>>user;
		if ( !(user==0 || user==1 || user==2) ){
			cout<<"please input right parameter."<<endl;
			continue;
		}
		int comput = rand() % (3);	//rand()产生随机整数,对3取余得到0/1/2
		cout<<"the computer choose "<<comput<<endl;
		if( user == 0 ){
			switch(comput){
			case 0:
				tmpRes = 2;
				break;
			case 1:
				tmpRes = 1;
				break;
			case 2:
				tmpRes = 0;
				break;
			default:
				tmpRes = -1;
				break;
			}
		}else{
			if( user == 1 ){
				switch(comput){
				case 0:
					tmpRes = 0;
					break;
				case 1:
					tmpRes = 2;
					break;
				case 2:
					tmpRes = 1;
					break;
				default:
					tmpRes = -1;
					break;
				}
			}else{
				//user==2
				switch(comput){
				case 0:
					tmpRes = 1;
					break;
				case 1:
					tmpRes = 0;
					break;
				case 2:
					tmpRes = 2;
					break;
				default:
					tmpRes = -1;
					break;
				}
			}
		}
		if ( tmpRes==res && res!=-1 ){
			cout<<"results for you(0-win,1-lose,2-draw) :"<<res;
			break;
		}else{
			res = tmpRes;
		}
	}
	system("pause");
	return 0;
}
