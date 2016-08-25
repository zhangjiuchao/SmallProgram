//求两个字符串的最大公共子串，这儿的子串不必连续 
#include<iostream>
#include<string>

using namespace std;

#define MAXSIZE 100

int lcsLength(string str1,string str2,int b[][MAXSIZE+1]);
void lcs(int i,int j,string str1,int b[][MAXSIZE+1]);
int main()
{
	string str1,str2;
	int b[MAXSIZE+1][MAXSIZE+1];  //b[i][j]表示字符str[i]和字符str[j]的匹配情况 
	int lcslen;
	cout<<"Please input two strings:"<<endl;
	cin>>str1>>str2;
	str1='0'+str1;
	str2='0'+str2;
	lcslen=lcsLength(str1,str2,b);
	cout<<"The length of the maximun commom sub sequence:"<<lcslen<<endl;
	cout<<"The maximum commom sub sequence:"<<endl;
	lcs(str1.length(),str2.length(),str1,b);
	cout<<"\n";
	return 0;
}

int lcsLength(string str1,string str2,int b[][MAXSIZE+1])
{
	int m=str1.length()-1,
	    n=str2.length()-1;
	int c[m+1][n+1];      //c[i][j]保存str1的前i个字符和 str2的前j个字符的公共子串的长度 
	for(int i=0;i<=m;++i) c[i][0]=0;
	for(int j=0;j<=n;++j) c[0][j]=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(str1[i]==str2[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=2;
			}
		}
	}
	return c[m][n];
}

void lcs(int i,int j,string str1,int b[][MAXSIZE+1])
{
	if(i>0&&j>0)
	{
		if(b[i][j]==0)
		{
			lcs(i-1,j-1,str1,b);
			cout<<str1[i];
		}
		else if(b[i][j]==1)
			lcs(i-1,j,str1,b);
		else
			lcs(i,j-1,str1,b);
	}
}
