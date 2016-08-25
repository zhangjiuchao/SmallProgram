#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	vector<int> vec;
	int num;
	cout<<"please input a list sorted numbers:"<<endl;
	while(cin>>num)
	{
		vec.push_back(num);
	}
	
	int i=0;
	for(int j=1;j<vec.size();++j)
	{
		if(vec[i] != vec[j])
		{
			++i;
			vec[i]=vec[j];
		}
	}
	
	for(int j=0;j<=i;++j)
		cout<<vec[j]<<" ";

	return 0;
}
