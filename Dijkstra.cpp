#include<iostream>
#include<cstdlib>
using namespace std; 
#define MAXSIZE 100
#define MAXVALUE 1000

void Dijk(int n,int v,double a[][MAXSIZE+1],double dist[],int pre[]);  //����Dijkstra�㷨�ҳ����������·�� 

int main()
{
    int pointNum,SP;
    cout<<"������ͼ�е�ĸ���: "; 
    cin>>pointNum;
    double *dist=new double[pointNum+1];  //���㵽ԭ������·�� 
    int *pre=new int[pointNum+1];         //���·���и����ǰ��ڵ� 
    double distMatrix[MAXSIZE+1][MAXSIZE+1]; //ͼ���ڽӾ��� 
    cout<<"������ͼ���ڽӾ���:"<<endl;
    for(int i=1;i<=pointNum;++i)
    {
        for(int j=1;j<=pointNum;++j)
        {
            cin>>distMatrix[i][j];
            if(distMatrix[i][j]==0)
                distMatrix[i][j]=MAXVALUE;        
        }        
    }
    cout<<"�������ͼ��Դ��: ";
    cin>>SP;
    Dijk(pointNum,SP,distMatrix,dist,pre);
    cout<<"���㵽Դ������·��Ϊ:"<<endl;
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
    
    for(int i=1;i<=n;++i)  //��ʼ�������Դ�� 
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
    
    for(int i=1;i<n;++i) //���� n-1 �Σ������е��� 
    {
        double temp=MAXVALUE;
        int u=v; 
        
        for(int j=1;j<=n;++j)    //�ҳ�δ��ǵĵ��е�Դ�������̵ĵ� 
        {
            if((!s[j])&&(dist[j]<temp)) 
            {
               u=j;
               temp=dist[j];                               
            }        
        }
        s[u]=true;
        
        for(int j=1;j<=n;++j)      //����δ��ǵ㵽Դ�����̾��� 
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
