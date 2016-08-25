#include<iostream>
#include<cstdlib>

using namespace std;
#define MAXSIZE 100
#define MAXVALUE 1000;
 
void prim(int n,double c[][MAXSIZE+1]);//用Prim算法求最小生成树 
int main()
{
    int pointNum;
    double  distMatrix[MAXSIZE+1][MAXSIZE+1];   //图的连通矩阵 
    cout<<"请输入连通图中点的个数: ";
    cin>>pointNum;
    cout<<"请输入图的邻接矩阵:"<<endl;
    for(int i=1;i<=pointNum;++i)
    {
        for(int j=1;j<=pointNum;++j)
        {
            cin>>distMatrix[i][j];
            if(distMatrix[i][j]==0)
                distMatrix[i][j]=MAXVALUE;        
        }        
    }
    cout<<"最小生成树为:"<<endl;
    prim(pointNum,distMatrix); 
    system("pause");
    return 0; 
}

void prim(int n,double c[][MAXSIZE+1])
{
     double *lowcost=new double[n+1];    //未选中点到各个已选中点的最小距离 
     int *closest=new int[n+1];          //与未选中点距离最近的已被选中点 
     bool *s=new bool[n+1];               //标记各点是否已被选中 
     s[1]=true;
     
     for(int i=2;i<=n;++i)      //初始化，把点1标为被2选中点 
     {
         lowcost[i]=c[1][i];
         closest[i]=1;
         s[i]=false;        
     }
     for(int i=1;i<n;++i)       //循环n-1次，则能选中n个点 
     {
         double min=MAXVALUE;
         int j; 
         for(int k=1;k<=n;++k)       //在未选中点的集合内挑选到已选中点集合中距离最近的点 
         {
             if((!s[k])&&(lowcost[k]<min))
             {
                  min=lowcost[k];                             
                  j=k;         
             }    
         }
         
         s[j]=true;
         cout<<"("<<j<<","<<closest[j]<<")"<<endl;
        
         for(int k=2;k<=n;++k)          //更新未选中点到已选中点的最短距离 
         {
             if((!s[k])&&(c[j][k]<lowcost[k]))
             {
                 lowcost[k]=c[j][k];
                 closest[k]=j;                                 
             }                
         }          
     } 
     delete [] lowcost;
     delete [] closest;
     delete [] s; 
} 
