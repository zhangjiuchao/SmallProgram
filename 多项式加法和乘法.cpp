#include<iostream>
#include<list>
#include<algorithm>
#include<cstdlib>

using namespace std;
//定义多项式的项 
typedef struct term{
	term(float num1,int num2):coef(num1),index(num2){};
	float coef;
	int index;
}Term;

//指数降序排列多项式的判定函数 
bool comp(const Term& t1,const Term& t2)
{
	return t1.index>t2.index;
}

void plusPolyList(const list<Term>& list1,const list<Term>& list2,list<Term>& list3); //list3=list1+list2
void multiplyPolyList(const list<Term>& list1,const list<Term>& list2,list<Term>& list3); //list3=list1*list2
void PrintPolyList(const list<Term>& list1);  //打印多项式 

int main()
{
	list<Term> PolyList_1;
	list<Term> PolyList_2;
	list<Term> PolyList_3;
	float num1;
	int num2;
	cout<<"Please input the first polyomial:"<<endl;
	cin>>num1>>num2;
	while(num1!=0.0||num2!=0)
	{
		if(num1!=0.0)
			PolyList_1.push_back(Term(num1,num2));
		cin>>num1>>num2;
	}
			
	cout<<"Please input the second polyomial:"<<endl;
	cin>>num1>>num2;
	while(num1!=0.0||num2!=0)
	{
		if(num1!=0.0)
			PolyList_2.push_back(Term(num1,num2));
		cin>>num1>>num2;
	}
			
	PolyList_1.sort(comp);   //先将两个多项式排序 
	PolyList_2.sort(comp);
	
	plusPolyList(PolyList_1,PolyList_2,PolyList_3);
	cout<<"plus the two polyomial:"<<endl;
	PrintPolyList(PolyList_3);
	
	PolyList_3.clear();
	cout<<"multiply the two polyomial:"<<endl;
	multiplyPolyList(PolyList_1,PolyList_2,PolyList_3);
	PrintPolyList(PolyList_3);
	
	system("pause");
	return 0;
}

void plusPolyList(const list<Term>& list1,const list<Term>& list2,list<Term>& list3)
{
	
	typedef list<Term>::const_iterator listIter;
	listIter it_1=list1.begin();
	listIter it_2=list2.begin();
	
	//循环list1和list2,若二者相等，则把系数相加，指数不变，写入list3
	//                 若*it_1的指数大于*it_2的指数，则把*it_1写入list3
	//                 若*it_1的指数小于*it_2的指数，则把*it_2写入list3
	while(it_1!=list1.end()&&it_2!=list2.end())  
	{
		if((*it_1).index==(*it_2).index)
		{
			Term t1((*it_1).coef+(*it_2).coef,(*it_1).index);
			list3.push_back(t1);
			++it_1;
			++it_2;
		}
		else if((*it_1).index>(*it_2).index)
		{
			list3.push_back(*it_1);
			++it_1;
		}
		else
		{
			list3.push_back(*it_2);
			++it_2;
		}
	}
	//如果list1中没有项，则把list2中的剩余项拷入list3中；
	//反之把list1中的剩余项拷入list3中 
	if(it_1==list1.end())
		list3.insert(list3.end(),it_2,list2.end());
	else
		list3.insert(list3.end(),it_1,list1.end());
}

void multiplyPolyList(const list<Term>& list1,const list<Term>& list2,list<Term>& list3)
{
	list<Term> mlist;
	typedef list<Term>::const_iterator Iter;
	Iter it=list2.begin();
	Iter it_end=list2.end();
	//用list2中的每一项乘以list1,结果加上前一次的结果，mlist作为中间链 
	while(it!=it_end)
	{
		list<Term> PL;
		for(list<Term>::const_iterator iter=list1.begin();iter!=list1.end();++iter)
		{
			Term temp((*it).coef*((*iter).coef),(*it).index+(*iter).index);
			PL.push_back(temp);
		}
		
		plusPolyList(list3,PL,mlist);
		list3.assign(mlist.begin(),mlist.end());
		mlist.clear();
		++it;
	}
}

void PrintPolyList(const list<Term>& list1)
{
	for(list<Term>::const_iterator it=list1.begin();it!=list1.end();++it)
		cout<<(*it).coef<<" "<<(*it).index<<"   ";
	cout<<endl; 
}
