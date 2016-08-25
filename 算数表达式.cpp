#include<iostream>
#include<stack>
using namespace std;

char Precede(char ch1,char ch2);
double Operate(double num1,char ch2,double num2);
int main()
{
	stack<char> OPTR;
	stack<double> OPND;
	char c,ch1;
	double num,num1,num2;
	OPTR.push('#');
	cout<<"Please input the expression:"<<endl;
	cin>>c;
	while(c!='#'||OPTR.top()!='#')
	{
		if(c>='0'&&c<='9')
		{
			num=(double)c-'0';
			OPND.push(num);
			cin>>c;
		}	
		else
		{
			switch(Precede(OPTR.top(),c))
			{
				case '<':
					OPTR.push(c);
					cin>>c;
					break;
				case '=':
					OPTR.pop();
					cin>>c;
					break;
				case '>':
					num1=OPND.top();
					OPND.pop();
					num2=OPND.top();
					OPND.pop();
					ch1=OPTR.top();
					OPTR.pop();
					OPND.push(Operate(num2,ch1,num1));
					break;	
			}
		}
	}
	
	cout<<"The result is:"<<OPND.top()<<endl;
	return 0;
}

char Precede(char ch1,char ch2)
{
	switch(ch1)
	{
		case '+':case '-':
			switch(ch2)
			{
				case '+':case '-':case ')':case '#':
					return '>';
				case '*':case '/':case '(':
					return '<';
			}
		case '*':case '/':
			switch(ch2)
			{
				case '+':case '-':case '*':case '/':case ')':case '#':
					return '>';
				case '(':
					return '<';
			}
		case '(':
			switch(ch2)
			{
				case '+':case '-':case '*':case '/':case '(':
					return '<';
				case ')':
					return '=';
			}
		case ')':
			return '>';
		case '#':
			if(ch2=='#')
				return '=';
			return '<';
		default:
			cerr<<"Input error!";
	}
}

double Operate(double num1,char ch,double num2)
{
	switch(ch)
		{
			case '+':
				return num1+num2;
			case '-':
				return num1-num2;
			case '*':
				return num1*num2;
			case '/':
				return num1/num2;
			default:
				cerr<<"Input error!!!";
		}
}

