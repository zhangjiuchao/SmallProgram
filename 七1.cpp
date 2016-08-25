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
	ifstream infile(file_name.c_str());//���û�ָ�����ļ�
	 
	if(infile)
	{
		map<string,long long> phone_file;//����map����� 
		
		string name;//�绰������ 
		long long phone_number;//�绰���� 
		
		typedef map<string,long long>::value_type valtype;
		
		//���ļ��ж�����Ϣ����д��phone_file���� 
		while(infile>>name>>phone_number)
			phone_file.insert(valtype(name,phone_number));
		infile.close();
		char ch='Q';
		while(ch!='O')
		{
			cout<<"Please choose your operation:A.seek    B.add    C.delete   O.finish your operation."<<endl;//��ʾ�û� ѡ����Ҫ�Ĳ��� 
			fflush(stdin);
			cin>>ch;
			switch (ch){
				case 'A'://�û����ҵ绰 
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
				
				case 'B'://�û���ӵ绰 
					{
						cout<<"Please input the name and phone_number:"<<endl;
						cin>>name>>phone_number;
						phone_file.insert(valtype(name,phone_number));
						break;
					}
				
				case 'C'://�û�ɾ���绰 
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
				case 'O'://�û��������� 
					break;
				default://���淶��������ʾ���� 
					cout<<"Sorry!Please choose right operation."<<"\n\n\n"<<endl;
				
			}
			cout<<"\n\n";
		}
		
		ofstream outfile(file_name.c_str());//�ٴδ�ָ�����ļ� 
		map<string,long long>::iterator iter=phone_file.begin();
		map<string,long long>::iterator iter_end=phone_file.end();
		while(iter!=iter_end)//����phone_file.����Ϣ����д���ļ� 
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

