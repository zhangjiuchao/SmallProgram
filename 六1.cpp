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
		cout<<"请依次输入：整数，无符号整数，长整数，浮点数，字符串："<<endl; 
		cin>>number1>>number2>>number3>>number4>>str;
		outfile<<number1<<"  "<<number2<<"  "<<number3<<"  "<<number4<<"  "<<str<<"\n";
		outfile<<"整数"<<number1<<"的十进制数为 "<<setw(10)<<number1<<"\n"
			<<"八进制数为 "<<setw(10)<<oct<<number1<<"\n"
			<<"十六进制数为 "<<setw(10)<<hex<<number1<<endl; 
		outfile.close();
	}
	else
		cout<<"ERROR:cannot open 'copy.txt' for output."<<endl;
	system("pause");
	return 0;
}

