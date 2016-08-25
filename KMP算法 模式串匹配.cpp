#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

//求next数组的函数 
void findnextval(char ch[],int next[]);

int main()
{
	const int MAXSIZE=100;  //字符串的最大长度 
	char str[MAXSIZE+1];    //主字符串 
	char substr[MAXSIZE+1];   //模式串 
	
	int lenth=0;
	char ch;
	cout<<"Please intput the string,end with #:"<<endl;
	cin>>ch;
	while(ch!='#')
	{
		++lenth;
		str[lenth]=ch;
		cin>>ch;
	}
	str[0]=lenth;        //字符串第一位存字符串长度
	fflush(stdin);
	cout<<"Please input the model string,end with #:"<<endl;
	cin>>ch;
	lenth=0;
	while(ch!='#')
	{
		++lenth;
		substr[lenth]=ch;
		cin>>ch;
	}
	substr[0]=lenth;
	
	int nextval[MAXSIZE+1];
	findnextval(substr,nextval);
	
	int i=1,j=1;
	while(i<=str[0]&&j<=substr[0])
	{
		if(j==0||str[i]==substr[j])
		{
			++i;
			++j;
		}
		else
			j=nextval[j];
	}
	if(j>substr[0])
		cout<<"match successfully,the position of substring in the string is:"<<i-substr[0]<<endl;
	else
		cout<<"match unsuccessfully!!!!";
	system("pause");
	return 0;
}

void findnextval(char ch[],int next[])
{
	int i=1,j=0;  next[i]=0;
	while(i<ch[0])
	{
		if(j==0||ch[i]==ch[j])
		{
			++i;
			++j;
			if(ch[i]==ch[j])
				next[i]=next[j];
			else
				next[i]=j;
		}
		else
			j=next[j];
	}
}
