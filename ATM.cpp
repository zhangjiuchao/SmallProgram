#include<iostream>
#include<cstdlib>
#include<string>
#include<map>
#include<cstdio>
using namespace std;

typedef struct{
	string name;
	string ID;
	string password;
	int money;
	int get;
}information,*INFORMATION;
int main()
{
		map<string,INFORMATION> accout;//����map����� 
		
		string str1,str2,str3,str4;
		int num,num1;
		INFORMATION secret=new information;
		typedef map<string,INFORMATION>::value_type valtype;
		
		cout<<"\n\n\n"
			<<"\t\t\tATM��ʹ��˵��\n"
			<<"\t\t1������һ���˻�\n"
			<<"\t\t2����¼�˻�\n"
			<<"\t\t3����ѯ�˻����\n"
			<<"\t\t4��ȡ��\n"
			<<"\t\t5����ʧ\n"
			<<"\t\t6���޸�����\n"
			<<"\t\t7��ת��\n\n\n";
			
		char go='Y',ok;
		int choose;
		while(go!='N')
		{
			cout<<"��ѡ���㽫Ҫ���еĲ�����1~7"<<endl;//��ʾ�û� ѡ����Ҫ�Ĳ��� 
			fflush(stdin);
			cin>>choose;
			switch (choose){
				case 1://����һ�����˻� 
					{
						cout<<"��������Ҫ�������˻���"<<endl;
						cin>>str1;
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it==accout.end())
						{
							cout<<"�����봴���˺ŵ�������ID������"<<endl; 
							cin>>str2>>str3>>str4;
							secret->name=str2;
							secret->ID=str3;
							secret->password=str4;
							secret->money=0;
							secret->get=1;
							accout.insert(valtype(str1,secret));
							cout<<"�����ɹ�"<<endl;
						}
						else
							cout<<"���˻��Ѵ���"<<endl; 
							
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl;	
						cin>>go;	
						break;
					}
				
				case 2://�û���¼�˺� 
					{
						cout<<"�������˺ţ�"<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end())
						{
							cout<<"���������룺"<<endl;
							cin>>str2;
							if((*it).second->password==str2)
								cout<<"��½�ɹ�"<<endl;
							else
								cout<<"�������"<<endl; 
						}
						else
							cout<<"���˺Ų�����"<<endl;
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl; 
						cin>>go;
						break;
					}
				
				case 3://�û���ѯ�˻� 
					{
						cout<<"�������˺ţ�"<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end())
						{
							cout<<"���������룺"<<endl;
							cin>>str2;
							if((*it).second->password==str2)
								cout<<"�˻����Ϊ: "<<(*it).second->money<<endl;
							else
								cout<<"�������"<<endl; 
						}
						else
							cout<<"���˺Ų�����"<<endl;
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl; 
						cin>>go;
						break;
					}
				case 4://�û�ȡ��
					{
						cout<<"�������˺ţ�"<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end()&&(*it).second->get==1)
						{
							cout<<"���������룺"<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								cout<<"�˻����Ϊ: "<<(*it).second->money<<endl;
								cout<<"������ȡ���";
								cin>>num;
								if(num<=(*it).second->money)
								{
									cout<<"ȡ��ɹ�����"<<endl;
									(*it).second->money-=num;
								}
								else
									cout<<"�˻����㣬ȡ��ʧ��"<<endl; 
							}		
							else
								cout<<"�������"<<endl; 
						}
						else
						{
							if(it==accout.end())
								cout<<"���˺Ų�����"<<endl;
							else
								cout<<"���˺��ѹ�ʧ���޷�ȡ��"<<endl; 
						}		
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl; 
						cin>>go;
						break;
					} 
				case 5://�û���ʧ 
					{
						cout<<"�������˺ţ�"<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end())
						{
							cout<<"���������룺"<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								(*it).second->get=0;
								cout<<"��ʧ�ɹ�������"<<endl; 
							}
							else
								cout<<"�������"<<endl; 
						}
						else
							cout<<"���˺Ų�����"<<endl;
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl; 
						cin>>go;
						break;
					}
				case 6://�û��޸����� 
					{
						cout<<"�������˺ţ�"<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end()&&(*it).second->get==1)
						{
							cout<<"���������룺"<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								cout<<"�����������룺";
								cin>>str1;
								cout<<"��ȷ�������룺"; 
								cin>>str2;
								if(str1==str2)
								{
									(*it).second->password=str1;
									cout<<"�����޸ĳɹ�"<<endl; 
								}
								else
									cout<<"�������벻һ�£��޸�ʧ��"<<endl; 
							}
							else
								cout<<"�������"<<endl; 
						}
						else
						{
							if((*it).second->get==0)
								cout<<"���˻��ѹ�ʧ���޷��޸�����"<<endl;
							else
								cout<<"���˺Ų�����"<<endl;
						}
							
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl; 
						cin>>go;
						break;
					}
				case 7://�û�ת�� 
					{
						cout<<"�������˺ţ�"<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end()&&(*it).second->get==1)
						{
							cout<<"���������룺"<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								cout<<"��������Ҫת����˺ţ�";
								cin>>str1;
								map<string,INFORMATION>::iterator iter=accout.find(str1);
								if(iter!=accout.end())
								{
									cout<<"ת����˻���ϢΪ��\n"
										<<"������"<<(*iter).second->name
										<<"\nID��"<<(*iter).second->ID
										<<"\nȷ��ת���밴 Y,�����밴 N\n";
									cin>>ok;
									if(ok=='Y')
									{
										cout<<"������ת���";
										cin>>num;
										if(num<=(*it).second->money)
										{
											(*it).second->money-=num;
											(*iter).second->money+=num;
											cout<<"ת�˳ɹ�"<<endl; 
										}
										else
											cout<<"������㣬ת��ʧ��"<<endl; 
									}
								}
								else
									cout<<"��ת����˺Ų�����"<<endl; 
							}
							else
								cout<<"�������"<<endl; 
						}
						else
						{
							if((*it).second->get==0)
								cout<<"���˻��ѹ�ʧ���޷�����ת��"<<endl;
							else
								 cout<<"���˺Ų�����"<<endl;
						} 
							
						cout<<"�Ƿ�������в�����\n"
							<<"�ǣ�Y     ��N"<<endl; 
						cin>>go;
						break;
					}	
				default://���淶��������ʾ���� 
					cout<<"Sorry!Please choose right operation."<<"\n\n\n"<<endl;
				
			}
			cout<<"\n\n";
		}
	system("pause");
	return 0;
}

