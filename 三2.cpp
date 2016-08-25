#include<iostream>
#include<cstdlib>

using namespace std;

void SetMatrix(int Matrix[][5]);
void OutputMatrix(int Matrix[][5]);
void AddMatrix(int Matrix1[][5],int Matrix2[][5],int Matrix3[][5]);
void MinusMatrix(int Matrix1[][5],int Matrix2[][5],int Marix3[][5]);

int main()
{
	//¶¯Ì¬·ÖÅä¾ØÕó¿Õ¼ä 
	int (*Matrix1)[5]=new int[4][5];
	int (*Matrix2)[5]=new int[4][5];
	int (*Matrix3)[5]=new int[4][5];
	
	cout<<"Please input the elements of Matrix1:"<<endl;
	SetMatrix(Matrix1);
	cout<<"Please input the elements of Matrix2:"<<endl;
	SetMatrix(Matrix2);
	
	AddMatrix(Matrix1,Matrix2,Matrix3);
	cout<<"Matrix1+Matrix2 is:"<<endl;
	OutputMatrix(Matrix3);
	
	MinusMatrix(Matrix1,Matrix2,Matrix3);
	cout<<"Matrix1-Matrix2 is:"<<endl;
	OutputMatrix(Matrix3);
	
	//ÊÍ·Å¾ØÕó¿Õ¼ä 
	delete[] Matrix1;
	delete[] Matrix2;
    delete[] Matrix3;
    
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

