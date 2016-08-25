#include<iostream>
#include<cstdlib>

using namespace std;
#define MAXSIZE 100
#define MAXVALUE 1000;
 
void prim(int n,double c[][MAXSIZE+1]);//��Prim�㷨����С������ 
int main()
{
    int pointNum;
    double  distMatrix[MAXSIZE+1][MAXSIZE+1];   //ͼ����ͨ���� 
    cout<<"��������ͨͼ�е�ĸ���: ";
    cin>>pointNum;
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
    cout<<"��С������Ϊ:"<<endl;
    prim(pointNum,distMatrix); 
    system("pause");
    return 0; 
}

void prim(int n,double c[][MAXSIZE+1])
{
     double *lowcost=new double[n+1];    //δѡ�е㵽������ѡ�е����С���� 
     int *closest=new int[n+1];          //��δѡ�е����������ѱ�ѡ�е� 
     bool *s=new bool[n+1];               //��Ǹ����Ƿ��ѱ�ѡ�� 
     s[1]=true;
     
     for(int i=2;i<=n;++i)      //��ʼ�����ѵ�1��Ϊ��2ѡ�е� 
     {
         lowcost[i]=c[1][i];
         closest[i]=1;
         s[i]=false;        
     }
     for(int i=1;i<n;++i)       //ѭ��n-1�Σ�����ѡ��n���� 
     {
         double min=MAXVALUE;
         int j; 
         for(int k=1;k<=n;++k)       //��δѡ�е�ļ�������ѡ����ѡ�е㼯���о�������ĵ� 
         {
             if((!s[k])&&(lowcost[k]<min))
             {
                  min=lowcost[k];                             
                  j=k;         
             }    
         }
         
         s[j]=true;
         cout<<"("<<j<<","<<closest[j]<<")"<<endl;
        
         for(int k=2;k<=n;++k)          //����δѡ�е㵽��ѡ�е����̾��� 
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
