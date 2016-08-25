#include<iostream>
#include<cstdlib>

using namespace std;

//定义矩阵类 
class Matrix{
	private:
		int rows,lines;
		int **ptr;
	public:
		Matrix(int a,int b);		
		Matrix(Matrix& M);
//		~Matrix();
//重载复制=操作符 
		Matrix& operator=(Matrix& M)
		{
			if(ptr!=M.ptr)
			{
				for(int i=0;i<rows;++i)
				{
					for(int j=0;j<lines;++j)
						ptr[i][j]=M.ptr[i][j]; 
				}
			}
			return *this;
		}
		
		void input();//输入矩阵元素的函数 
		
		void output();//输出矩阵元素的函数 
		
		Matrix& Add(Matrix& M);//矩阵的加法 
		
		Matrix& Minus(Matrix& M);//矩阵的减法 
};

Matrix::Matrix(int a,int b)
{
	rows=a;lines=b;
	ptr=new int*[a];
	for(int i=0;i<a;++i)
		ptr[i]=new int[b];
}

Matrix::Matrix(Matrix& M)
{
	rows=M.rows;
	lines=M.lines;
	ptr=M.ptr;
}

/*Matrix::~Matrix()
{
	for(int i=0;i<rows;++i)
		delete[] ptr[i];
	delete[] ptr;
}*/

void Matrix::input()
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<lines;++j)
			cin>>(ptr[i])[j];
	}
}

void Matrix::output()
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<lines;++j)
			cout<<(ptr[i])[j]<<" ";
		cout<<endl;
	}
}

Matrix& Matrix::Add(Matrix& M)
{
	Matrix P(rows,lines);
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<=lines;++j)
			(P.ptr[i])[j]=(ptr[i])[j]+(M.ptr[i])[j];
	}
	Matrix &rP=P;
	return rP;
}

Matrix& Matrix::Minus(Matrix& M)
{
	Matrix P(rows,lines);
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<=lines;++j)
			(P.ptr[i])[j]=(ptr[i])[j]-(M.ptr[i])[j];
	}
	Matrix &rP=P;
	return rP;
}
void SetMatrix(int **A,int rows,int lines)
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<lines;++j)
		{
			cin>>A[i][j];
		}
	}
}
void OutputMatrix(int **A,int rows,int lines)
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<lines;++j)
			cout<<A[i][j]<<" ";
		cout<<"\n";
	}
}
void AddMatrix(int **A1,int **A2,int **A3,int rows,int lines)
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<lines;++j)
			A3[i][j]=A1[i][j]+A2[i][j];
	}
}
void MinusMatrix(int **A1,int **A2,int **A3,int rows,int lines)
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<lines;++j)
			A3[i][j]=A1[i][j]-A2[i][j];
	}
}


int main()
{
	int iRows,iLines;
	cout<<"Please input the rows and lines of matrix:"<<endl;
	cin>>iRows>>iLines;
	
	int **A1,**A2,**A3;
	A1=new int*[iRows];
	A2=new int*[iRows];
	A3=new int*[iRows];
	for(int i=0;i<iLines;++i)
	{
		A1[i]=new int[iLines];
		A2[i]=new int[iLines];
		A3[i]=new int[iLines];
	}
	cout<<"Please input the elements of matrix A1:"<<endl;
	SetMatrix(A1,iRows,iLines);
	cout<<"Please input the elements of matrix A2:"<<endl;
	SetMatrix(A2,iRows,iLines);
	
   	AddMatrix(A1,A2,A3,iRows,iLines);
   	cout<<"A1+A2 is:"<<endl;
	OutputMatrix(A3,iRows,iLines);
	
	MinusMatrix(A1,A2,A3,iRows,iLines);
	cout<<"A1-A2 is:"<<endl;
	OutputMatrix(A3,iRows,iLines);

	//声明矩阵类的对象 
	Matrix pA1(iRows,iLines),pA2(iRows,iLines),pA3(iRows,iLines);
	Matrix &rpA2=pA2;
	cout<<"Please input the elements of Matrix(pA1):"<<endl;
	pA1.input();
	cout<<"Please input the elements of Matrix(pA2):"<<endl;
	pA2.input();
	pA3=pA1.Add(rpA2);
	cout<<"pA1+pA2 is:" <<endl;
	pA3.output();
	pA3=pA1.Minus(rpA2);
	cout<<"pA1-pA2 is:"<<endl;
	pA3.output();
	
/*	for(int i=0;i<iLines;++i)
	{
		delete[] A1[i];
		delete[] A2[i];
		delete[] A3[i];
	}
	delete[] A1;
	delete[] A2;
	delete[] A3;*/
	
	system("pause");
	return 0;
}

