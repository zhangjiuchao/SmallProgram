#include<cstdlib>
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	ofstream outfile("copy.txt");
	 
	if(outfile)
	{
		int number1;
		unsigned int number2;
		long number3;
		double number4;
		char ch;
		string str;
		cout<<"���������룺�������޷��������������������������ַ�����"<<endl; 
		cin>>number1>>number2>>number3>>number4>>str;
		outfile<<number1<<"  "<<number2<<"  "<<number3<<"  "<<number4<<"  "<<str<<"\n";
		outfile<<"����"<<number1<<"��ʮ������Ϊ "<<setw(10)<<number1<<"\n"
			<<"�˽�����Ϊ "<<setw(10)<<oct<<number1<<"\n"
			<<"ʮ��������Ϊ "<<setw(10)<<hex<<number1<<endl; 
		outfile.close();
	}
	else
		cout<<"ERROR:cannot open 'copy.txt' for output."<<endl;
	system("pause");
	return 0;
}

