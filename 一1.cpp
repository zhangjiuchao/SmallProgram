#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

main()
{
	int random_num;
	srand(time(NULL));//�Ե�ǰʱ����Ϊ��������� 
	
	random_num=(rand()%1000)+1;//�õ�1~1000������� 
	int number2(0);
	cout<<"Please guess the price of goods(1~1000)."<<endl;
	
	while(number2!=random_num)
	{
		cin>>number2;
		if(number2>0&&number2<=1000)
		{
			if(number2<random_num)
				cout<<"Please input a larger number."<<endl;
			else
				cout<<"Please input a smaller number."<<endl;
		}
		else
			cout<<"ERROR!!please input a number between 1 and 1000 again.."<<endl;
	}
	cout<<"Congratulation! you are right."<<endl;
	return 0;
}
