#include<iostream>
#include<cstdlib>
#include<string>
#include<map>
#include<fstream>
//#include<cstdio>
using namespace std;

int main()
{
	string file_name;
	
	cout<<"Please input the name of the file to open:"<<endl;
	cin>>file_name;
	ifstream infile(file_name.c_str());//打开用户指定的文件
	 
	if(infile)
	{
		map<string,long long> phone_file;//创建map类对象 
		
		string name;//电话的名字 
		long long phone_number;//电话号码 
		
		typedef map<string,long long>::value_type valtype;
		
		//从文件中读出信息，并写入phone_file里面 
		while(infile>>name>>phone_number)
			phone_file.insert(valtype(name,phone_number));
		infile.close();
		char ch='Q';
		while(ch!='O')
		{
			cout<<"Please choose your operation:A.seek    B.add    C.delete   O.finish your operation."<<endl;//提示用户 选择需要的操作 
			fflush(stdin);
			cin>>ch;
			switch (ch){
				case 'A'://用户查找电话 
					{
						cout<<"Please input the name to seek:"<<endl;
						cin>>name;
						map<string,long long>::iterator it=phone_file.find(name);
						if(it!=phone_file.end())
							cout<<"His/her phone_number is: "<<(*it).second<<endl;
						else
							cout<<"Sorry!the name doesn't exist."<<endl;		
						break;
					}
				
				case 'B'://用户添加电话 
					{
						cout<<"Please input the name and phone_number:"<<endl;
						cin>>name>>phone_number;
						phone_file.insert(valtype(name,phone_number));
						break;
					}
				
				case 'C'://用户删除电话 
					{
						cout<<"Please input the name to delete:"<<endl;
						cin>>name;
						map<string,long long>::iterator it=phone_file.find(name);
						if(it==phone_file.end())
							cout<<"Sorry. "<<name<<" not found"<<endl;
						else
						{
							phone_file.erase(it);
							cout<<"ok: "<<name<<" removed!"<<endl;
						}
						break;
					}
				case 'O'://用户结束操作 
					break;
				default://不规范操作，提示错误 
					cout<<"Sorry!Please choose right operation."<<"\n\n\n"<<endl;
				
			}
			cout<<"\n\n";
		}
		
		ofstream outfile(file_name.c_str());//再次打开指定的文件 
		map<string,long long>::iterator iter=phone_file.begin();
		map<string,long long>::iterator iter_end=phone_file.end();
		while(iter!=iter_end)//遍历phone_file.把信息重新写回文件 
		{
			outfile<<(*iter).first<<"\t"<<(*iter).second<<endl;
			iter++;
		}
		outfile.close();
	}
	else
		cout<<"ERROR!!"<<endl;
	system("pause");
	return 0;
}

