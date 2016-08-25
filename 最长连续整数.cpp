#include<iostream>

using namespace std;

int main()
{
	int num[10005];
	
	int hash[10000]={0};
	
	cout<<"Input:"<<endl;
	
	int lenth=0;
	int integer;
	
	while(cin>>integer)
	{
		num[lenth++]=integer;
	}
	
    for(int i=0;i<lenth;++i)
	{
		hash[num[i]]=1;
	}
	
	int start;
	int end;
	int bestlenth=1;
	bool flag;
	for(int i=0;i<lenth;++i)
	{
		start=num[i];
		end=num[i];
		flag=true;
		
		while(flag)
		{
			end+=1;
			if(!hash[end])
			{
				flag=false;
				if(bestlenth<(end-start))
					bestlenth=end-start;
			}
			
		}
	}
	
	cout<<"bestlenth is: "<<bestlenth<<endl;
	return 0;
}

