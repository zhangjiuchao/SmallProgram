#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream> 
using namespace std;

class NQueen{
public:
      int N;
      int sum;
      int *x;
      NQueen(int n)
      {
          N=n;
          sum=0;
          x=new int [n+1];
          for(int i=0;i<=n;++i)
             x[i]=0;            
      }
      ~NQueen()
      {
         delete [] x;         
      }
      bool place(int k)
      {
          for(int i=1;i<k;++i)
          {
             if((abs(k-i)==abs(x[k]-x[i]))||x[k]==x[i])
                 return false;
          }
          return true;
      }
      void backtrace();      
};

void NQueen::backtrace()
{
     ofstream out("aa.txt"); 
     x[1]=0;
     int k=1;
     while(k>0)
     {
         x[k]+=1;
         while((x[k]<=N)&&(!(place(k))))
             x[k]+=1;
         if(x[k]<=N)
         {
             if(k==N)
             {
                 sum+=1;
                 out<<"��"<<sum<<"�ַ��÷���Ϊ:"<<endl; 
                 for(int i=1;i<=N;++i)
                 {
                    for(int j=1;j<x[i];++j)
                            out<<"0 ";
                    out<<"1 ";
                    for(int j=x[i]+1;j<=N;++j)
                        out<<"0 ";
                    out<<"\n";
                 }
             }
             else
             {
                 k++;
                 x[k]=0;
             }
         }
         else
             k--;
     }
     out.close(); 
     if(sum==0)
         cout<<"�����ڷ��������ķ��÷���!"<<endl; 
}

int main(void)
{
   int nn;
   cout<<"������ʺ�ĸ���: ";
   cin>>nn;
   NQueen myQueen(nn);
   myQueen.backtrace(); 
   system("pause");
   return 0; 
}  
