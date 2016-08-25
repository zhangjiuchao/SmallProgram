#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string file_name;
	
	cout<<"file_name:"<<endl;//输出需要打开的文件 
	cin>>file_name;
	ifstream infile(file_name.c_str());
	
	if(infile)
	{
		ofstream outfile("_COPY.txt");
		if(outfile)
		{
			cout<<"OK"<<endl;
			string str;
			int i=0;
			
			while(getline(infile,str))
			{
				i++;
				outfile<<"("<<i<<") ";
				outfile<<str<<endl;
			}
			outfile.close();
		}
		infile.close();			
	}
	else
		cerr<<"ERROR"<<endl;
	system("pause");
	return 0;
}

