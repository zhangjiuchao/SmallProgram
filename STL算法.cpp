#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
template<typename T>
class addnumber:
	public unary_function<T,T>
	{
		public:
		addnumber(T t): number(t){};
		T operator()(T snum)
		{
			return snum+number;
		}
		private:
			T number;
	};

main()
{
	vector<int> ivec;
	list<int> ilist;
	for(int i=1;i<=10;++i)
		ivec.push_back(i);
	copy(ivec.begin(),ivec.end(),ostream_iterator<int>(cout," "));
	cout<<"\n";
	
	copy(ivec.begin(),ivec.end(),front_inserter(ilist));
	copy(ilist.begin(),ilist.end(),ostream_iterator<int>(cout," "));
	cout<<"\n";
	swap_ranges(ivec.begin(),ivec.end(),ilist.begin());
	copy(ivec.begin(),ivec.end(),ostream_iterator<int>(cout," "));
	cout<<"\n";
	copy(ilist.begin(),ilist.end(),ostream_iterator<int>(cout," "));
	cout<<"\n";
	transform(ivec.begin(),ivec.end(),ilist.begin(),addnumber<int>(100));
	copy(ilist.begin(),ilist.end(),ostream_iterator<int>(cout," "));
	cout<<"\n";
	
	ifstream infine("stl.txt");
	string str((istreambuf_iterator<char>(infine)),istreambuf_iterator<char>());
	infine.close();
	cout<<str<<endl;
	return 0;
}

