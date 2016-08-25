#include<iostream>
#include<stack>
#include<cstdlib> 
using namespace std;

bool parencomp(char ch1,char ch2)
{
	if(ch1=='['&&ch2==']')
		return true;
	if(ch1=='('&&ch2==')')
	    return true;
	return false;
}

int main()
{
	stack<char> Stack;
	char ch;
	Stack.push('#');  //ջ�׷�һ�� # ��ʾջ�ף�������� 
	
	while(cin>>ch)   //ѭ����ȡ�ַ� 
	{
		if(parencomp(Stack.top(),ch))
			Stack.pop();
		else
			Stack.push(ch);
	}
	if(Stack.size()==1)
		cout<<"Match successfully!"<<endl;
	else
	    cout<<"Match unsuccessfully!"<<endl;
	system("pause");
	return 0;
}

