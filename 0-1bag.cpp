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
     cout<<"请输入货物的件数: ";
     cin>>goodsNum;
     double *value=new double[goodsNum+1]; //每件存储货物的价值 ; 
     int *weight=new int[goodsNum+1];       //存储每件货物的质量 ; 
     double m[wMAXSIZE+1][cMAXSIZE+1];      //m[i][j] 表示背包容量为 j,可选择物品为 i,i+1,i+2,....n,时的最优值 ; 
     int C;                                 //背包的最大容量 ; 
     
     cout<<"请输入每件货物的质量:"<<endl;
     for(int i=1;i<=goodsNum;++i)
         cin>>weight[i];
         
     cout<<"请输入每件货物对应的价值:"<<endl;
     for(int i=1;i<=goodsNum;++i)
         cin>>value[i];
         
     cout<<"请输入背包的最大承受重量: ";
     cin>>C;
     
     knapsack(goodsNum,value,weight,C,m);     //运用动态规划求出每个 m[i][j]; 
     
     
     cout<<"装载的最优方案为:"<<endl;
     
     traceback(goodsNum,m,weight,C);         //根据 m[i][j] 求出装载方案； 
     
     cout<<"\n装载的最大价值为: "<<m[1][C]<<endl;
     
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
      
