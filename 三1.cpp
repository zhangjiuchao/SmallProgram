#include<iostream>
#include<cstdlib>

using namespace std;

void SetMatrix(int Matrix[][5]);//初始化矩阵的函数 
void OutputMatrix(int Matrix[][5]);//输出矩阵元素的函数 
void AddMatrix(int Matrix1[][5],int Matrix2[][5],int Matrix3[][5]);//把两个矩阵相加的函数 
void MinusMatrix(int Matrix1[][5],int Matrix2[][5],int Marix3[][5]);//把两个矩阵相减的函数 

int main()
{
	int Matrix1[4][5],Matrix2[4][5],Matrix3[4][5];//定义三个4*5的矩阵 
	
	cout<<"Please input the elements of Matrix1:"<<endl;
	SetMatrix(Matrix1);
	cout<<"Please input the elements of Matrix2:"<<endl;
	SetMatrix(Matrix2);
	
	AddMatrix(Matrix1,Matrix2,Matrix3);//Matrix3=Matrix1+Matrix2
	cout<<"Matrix1+Matrix2 is:"<<endl;
	OutputMatrix(Matrix3);
	
	MinusMatrix(Matrix1,Matrix2,Matrix3);//Matrix3=Matrix1-Matrix2
	cout<<"Matrix1-Matrix2 is:"<<endl;
	OutputMatrix(Matrix3);
	
	system("pause");
	return 0;
}


void SetMatrix(int Matrix[][5])
{
	for(int i=0;i<=3;++i)
	{
		for(int j=0;j<=4;++j)
		{
			cin>>Matrix[i][j];
		}
	}
}

void OutputMatrix(int Matrix[][5])
{
	for(int i=0;i<=3;++i)
	{
		for(int j=0;j<=4;++j)
			cout<<Matrix[i][j]<<" ";
		cout<<"\n";
	}
}

void AddMatrix(int Matrix1[][5],int Matrix2[][5],int Matrix3[][5])
{
	for(int i=0;i<=3;++i)
	{
		for(int j=0;j<=4;++j)
			Matrix3[i][j]=Matrix1[i][j]+Matrix2[i][j];
	}
}

void MinusMatrix(int Matrix1[][5],int Matrix2[][5],int Matrix3[][5])
{
	for(int i=0;i<=3;++i)
	{
		for(int j=0;j<=4;++j)
			Matrix3[i][j]=Matrix1[i][j]-Matrix2[i][j];
	}
}

