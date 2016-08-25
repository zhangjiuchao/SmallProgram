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
		map<string,INFORMATION> accout;//创建map类对象 
		
		string str1,str2,str3,str4;
		int num,num1;
		INFORMATION secret=new information;
		typedef map<string,INFORMATION>::value_type valtype;
		
		cout<<"\n\n\n"
			<<"\t\t\tATM机使用说明\n"
			<<"\t\t1、创建一个账户\n"
			<<"\t\t2、登录账户\n"
			<<"\t\t3、查询账户余额\n"
			<<"\t\t4、取款\n"
			<<"\t\t5、挂失\n"
			<<"\t\t6、修改密码\n"
			<<"\t\t7、转账\n\n\n";
			
		char go='Y',ok;
		int choose;
		while(go!='N')
		{
			cout<<"请选择你将要进行的操作：1~7"<<endl;//提示用户 选择需要的操作 
			fflush(stdin);
			cin>>choose;
			switch (choose){
				case 1://创建一个新账户 
					{
						cout<<"请输入需要创建的账户号"<<endl;
						cin>>str1;
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it==accout.end())
						{
							cout<<"请输入创建账号的姓名、ID、密码"<<endl; 
							cin>>str2>>str3>>str4;
							secret->name=str2;
							secret->ID=str3;
							secret->password=str4;
							secret->money=0;
							secret->get=1;
							accout.insert(valtype(str1,secret));
							cout<<"创建成功"<<endl;
						}
						else
							cout<<"该账户已存在"<<endl; 
							
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl;	
						cin>>go;	
						break;
					}
				
				case 2://用户登录账号 
					{
						cout<<"请输入账号："<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end())
						{
							cout<<"请输入密码："<<endl;
							cin>>str2;
							if((*it).second->password==str2)
								cout<<"登陆成功"<<endl;
							else
								cout<<"密码错误"<<endl; 
						}
						else
							cout<<"此账号不存在"<<endl;
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl; 
						cin>>go;
						break;
					}
				
				case 3://用户查询账户 
					{
						cout<<"请输入账号："<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end())
						{
							cout<<"请输入密码："<<endl;
							cin>>str2;
							if((*it).second->password==str2)
								cout<<"账户余额为: "<<(*it).second->money<<endl;
							else
								cout<<"密码错误"<<endl; 
						}
						else
							cout<<"此账号不存在"<<endl;
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl; 
						cin>>go;
						break;
					}
				case 4://用户取款
					{
						cout<<"请输入账号："<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end()&&(*it).second->get==1)
						{
							cout<<"请输入密码："<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								cout<<"账户余额为: "<<(*it).second->money<<endl;
								cout<<"请输入取款金额：";
								cin>>num;
								if(num<=(*it).second->money)
								{
									cout<<"取款成功！！"<<endl;
									(*it).second->money-=num;
								}
								else
									cout<<"账户余额不足，取款失败"<<endl; 
							}		
							else
								cout<<"密码错误"<<endl; 
						}
						else
						{
							if(it==accout.end())
								cout<<"此账号不存在"<<endl;
							else
								cout<<"此账号已挂失，无法取款"<<endl; 
						}		
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl; 
						cin>>go;
						break;
					} 
				case 5://用户挂失 
					{
						cout<<"请输入账号："<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end())
						{
							cout<<"请输入密码："<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								(*it).second->get=0;
								cout<<"挂失成功！！！"<<endl; 
							}
							else
								cout<<"密码错误"<<endl; 
						}
						else
							cout<<"此账号不存在"<<endl;
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl; 
						cin>>go;
						break;
					}
				case 6://用户修改密码 
					{
						cout<<"请输入账号："<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end()&&(*it).second->get==1)
						{
							cout<<"请输入密码："<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								cout<<"请输入新密码：";
								cin>>str1;
								cout<<"请确认新密码："; 
								cin>>str2;
								if(str1==str2)
								{
									(*it).second->password=str1;
									cout<<"密码修改成功"<<endl; 
								}
								else
									cout<<"两次密码不一致，修改失败"<<endl; 
							}
							else
								cout<<"密码错误"<<endl; 
						}
						else
						{
							if((*it).second->get==0)
								cout<<"该账户已挂失，无法修改密码"<<endl;
							else
								cout<<"此账号不存在"<<endl;
						}
							
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl; 
						cin>>go;
						break;
					}
				case 7://用户转账 
					{
						cout<<"请输入账号："<<endl;
						cin>>str1;
						
						map<string,INFORMATION>::iterator it=accout.find(str1);
						if(it!=accout.end()&&(*it).second->get==1)
						{
							cout<<"请输入密码："<<endl;
							cin>>str2;
							if((*it).second->password==str2)
							{
								cout<<"请输入需要转入的账号：";
								cin>>str1;
								map<string,INFORMATION>::iterator iter=accout.find(str1);
								if(iter!=accout.end())
								{
									cout<<"转入的账户信息为：\n"
										<<"姓名："<<(*iter).second->name
										<<"\nID："<<(*iter).second->ID
										<<"\n确认转账请按 Y,否则请按 N\n";
									cin>>ok;
									if(ok=='Y')
									{
										cout<<"请输入转入金额：";
										cin>>num;
										if(num<=(*it).second->money)
										{
											(*it).second->money-=num;
											(*iter).second->money+=num;
											cout<<"转账成功"<<endl; 
										}
										else
											cout<<"你的余额不足，转账失败"<<endl; 
									}
								}
								else
									cout<<"待转入的账号不存在"<<endl; 
							}
							else
								cout<<"密码错误"<<endl; 
						}
						else
						{
							if((*it).second->get==0)
								cout<<"该账户已挂失，无法进行转账"<<endl;
							else
								 cout<<"此账号不存在"<<endl;
						} 
							
						cout<<"是否继续进行操作？\n"
							<<"是：Y     否：N"<<endl; 
						cin>>go;
						break;
					}	
				default://不规范操作，提示错误 
					cout<<"Sorry!Please choose right operation."<<"\n\n\n"<<endl;
				
			}
			cout<<"\n\n";
		}
	system("pause");
	return 0;
}

