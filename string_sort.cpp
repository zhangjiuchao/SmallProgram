#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;

#define MAXSIZE 10

template <class ST>
struct comp{
	bool operator()(const ST& str1,const ST& str2)
	{
		return str1>str2;
	}
};

int main()

{
	int num;
	vector<int> vec;
	printf("Please input %d numbers:\n",MAXSIZE);
	for(int i=0;i<MAXSIZE;++i)
	{
		scanf("%d",&num);
		vec.push_back(num);
	}
	
	sort(vec.begin(),vec.end(),comp<int>());
	vector<int>::iterator it=vec.begin();
	for(;it!=vec.end();++it)
		cout<<*it<<"  "<<endl;
	
	return 0;
}

