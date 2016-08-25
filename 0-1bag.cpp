#include<iostream>
#include<cstdlib> 

using namespace std;

#define wMAXSIZE 100
#define cMAXSIZE 1000

void knapsack(int n,double v[],int w[],int c,double m[][cMAXSIZE+1]);
void traceback(int n,double m[][cMAXSIZE+1],int w[],int c);

int main()
{
     int goodsNum;
     cout<<"���������ļ���: ";
     cin>>goodsNum;
     double *value=new double[goodsNum+1]; //ÿ���洢����ļ�ֵ ; 
     int *weight=new int[goodsNum+1];       //�洢ÿ����������� ; 
     double m[wMAXSIZE+1][cMAXSIZE+1];      //m[i][j] ��ʾ��������Ϊ j,��ѡ����ƷΪ i,i+1,i+2,....n,ʱ������ֵ ; 
     int C;                                 //������������� ; 
     
     cout<<"������ÿ�����������:"<<endl;
     for(int i=1;i<=goodsNum;++i)
         cin>>weight[i];
         
     cout<<"������ÿ�������Ӧ�ļ�ֵ:"<<endl;
     for(int i=1;i<=goodsNum;++i)
         cin>>value[i];
         
     cout<<"�����뱳��������������: ";
     cin>>C;
     
     knapsack(goodsNum,value,weight,C,m);     //���ö�̬�滮���ÿ�� m[i][j]; 
     
     
     cout<<"װ�ص����ŷ���Ϊ:"<<endl;
     
     traceback(goodsNum,m,weight,C);         //���� m[i][j] ���װ�ط����� 
     
     cout<<"\nװ�ص�����ֵΪ: "<<m[1][C]<<endl;
     
     delete [] value;
     delete [] weight;
     system("pause");
     return 0; 
}  

void knapsack(int n,double v[],int w[],int c,double m[][cMAXSIZE+1])
{
     int jmax=(w[n]-1>c)?c:w[n]-1;
     for(int j=0;j<=jmax;++j)
         m[n][j]=0;
     for(int j=w[n];j<=c;++j)
         m[n][j]=v[n];
         
     for(int i=n-1;i>1;--i)
     {
         jmax=(w[i]-1>c)?c:w[i];
         for(int j=0;j<=jmax;++j)
             m[i][j]=m[i+1][j];
         for(int j=w[i];j<=c;++j)
             m[i][j]=(m[i+1][j]>m[i+1][j-w[i]]+v[i])?m[i+1][j]:m[i+1][j-w[i]]+v[i];      
     }      
     m[1][c]=m[2][c];
     if(c>=w[1])
          m[1][c]=(m[2][c]>m[2][c-w[1]]+v[1])?m[2][c]:m[2][c-w[1]]+v[1];    
}

void traceback(int n,double m[][cMAXSIZE+1],int w[],int c)
{
    for(int i=1;i<=n-1;++i)
    {
        if(m[i][c]==m[i+1][c]) 
            cout<<"0 ";
        else
        {
            cout<<"1 ";
            c-=w[i];    
        }        
    }
    if(m[n][c]>0)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl; 
} 
      
