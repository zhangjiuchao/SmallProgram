/***************fast sort*************/ 

#include<iostream>
#include<vector>

using namespace std;

int Partion(vector<int>& vec,int num1,int num2)
{
	int key=vec[num1];
	while(num1<num2)
	{
		while(num1<num2&&vec[num2]>=key)
			--num2;
		vec[num1]=vec[num2];
		while(num1<num2&&vec[num1]<=key)
			++num1;
		vec[num2]=vec[num1];
	}
	vec[num1]=key;
	return num1;
}
void VSort(vector<int>& vec,int num1,int num2)
{
	int pivotloc;
	if(num1<num2)
	{
		pivotloc=Partion(vec,num1,num2);
		VSort(vec,num1,pivotloc-1);
		VSort(vec,pivotloc+1,num2);
	}
}

main()
{
	vector<int> vec;
	int num,count=0;
	cout<<"Please input the numbers:"<<endl;
	while(cin>>num)
	{
		++count;
		vec.push_back(num);
	}
		
	VSort(vec,0,count-1);
	vector<int>::iterator it=vec.begin(),
						  iter=vec.end();
	
	while(it!=iter)
	{
		cout<<*it<<"  ";
		++it;
	}
	cout<<endl;
	return 0;
}

