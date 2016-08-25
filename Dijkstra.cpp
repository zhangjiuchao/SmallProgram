#include<iostream>
#include<cstdlib>
using namespace std; 
#define MAXSIZE 100
#define MAXVALUE 1000

void Dijk(int n,int v,double a[][MAXSIZE+1],double dist[],int pre[]);  //利用Dijkstra算法找出两点间的最短路径 

int main()
{
    int pointNum,SP;
    cout<<"请输入图中点的个数: "; 
    cin>>pointNum;
    double *dist=new double[pointNum+1];  //各点到原点的最短路径 
    int *pre=new int[pointNum+1];         //最短路径中各点的前向节点 
    double distMatrix[MAXSIZE+1][MAXSIZE+1]; //图的邻接矩阵 
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
    cout<<"请输入此图的源点: ";
    cin>>SP;
    Dijk(pointNum,SP,distMatrix,dist,pre);
    cout<<"各点到源点的最短路径为:"<<endl;
    for(int i=1;i<=pointNum;++i)
        cout<<dist[i]<<" ";
    cout<<endl;
    delete [] dist;
    delete [] pre; 
    system("pause");
    return 0; 
}

void Dijk(int n,int v,double a[][MAXSIZE+1],double dist[],int pre[])
{
    if(v<1||v>n) return;
    bool *s=new bool[n+1];
    
    for(int i=1;i<=n;++i)  //初始化，标记源点 
    {
        dist[i]=a[v][i];
        s[i]=false;
        if(dist[i]==MAXVALUE)
            pre[i]=0;
        else
            pre[i]=v; 
    }
    dist[v]=0;
    s[v]=true;
    
    for(int i=1;i<n;++i) //遍历 n-1 次，将所有点标记 
    {
        double temp=MAXVALUE;
        int u=v; 
        
        for(int j=1;j<=n;++j)    //找出未标记的点中到源点距离最短的点 
        {
            if((!s[j])&&(dist[j]<temp)) 
            {
               u=j;
               temp=dist[j];                               
            }        
        }
        s[u]=true;
        
        for(int j=1;j<=n;++j)      //更新未标记点到源点的最短距离 
        {
            if((!s[j])&&(a[u][j]<MAXVALUE)) 
            {
                if(dist[u]+a[u][j]<dist[j])
                {
                    dist[j]=dist[u]+a[u][j];
                    pre[j]=u;                           
                }   
            }        
        }     
    }  
    delete [] s; 
}
