#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<iterator>
using namespace std;
//�������ڵ� 
typedef struct node{
	node(){};
	node(float num1,int num2,int num3,int num4):weight(num1),parent(num2),lchild(num3),rchild(num4){};
	float weight;
	int parent,lchild,rchild;
}Node;

void select(const Node huffmantree[],const int num1,int &num2,int &num3); //��ѡ���нڵ���weight ��С�������ڵ� 

int main()
{
	float num;
	int count;
	cout<<"Please input the number: ";  //�����ַ��ĸ��� 
	cin>>count;
	Node *huffmantree=new Node [2*count];
	if(!huffmantree) cerr<<"ERROE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	cout<<"Please input the weights:"<<endl;   //����Ȩ�� 
	int i=1;
	//���������Ҷ�ӽڵ� 
	for(;i<=count;++i)
	{
		cin>>num;
		huffmantree[i]=Node(num,0,0,0);
	}
	//������Ҫ���м�ڵ� 
	for(;i<=2*count-1;++i)
		huffmantree[i]=Node(0,0,0,0);
	int j;
	
	//����huffmantree 
	for(int k=count+1;k<=2*count-1;++k)
	{
		select(huffmantree,k-1,i,j);
		huffmantree[i].parent=k;
		huffmantree[j].parent=k;
		huffmantree[k].lchild=i;
		huffmantree[k].rchild=j;
		huffmantree[k].weight=huffmantree[i].weight+huffmantree[j].weight;
	}
	
	char *code=new char[count+2];  //��ű��������
	code[count+1]='\0';
	//��Ҷ�ӽڵ���ʵ����ڵ㣬���ÿ���ַ��Ĺ��������룬����Ϊ0���Һ���Ϊ1
	for(int i=1;i<=count;++i)
	{
		int start=count;
		for(int c=i,pp=huffmantree[c].parent;pp!=0;c=pp,pp=huffmantree[c].parent)
		{
			if(huffmantree[pp].lchild==c)
				code[start]='0';
			if(huffmantree[pp].rchild==c)
				code[start]='1';
			--start;
		}
		
		cout<<huffmantree[i].weight<<" huffmancode is:";
		printf("%s\n",code+start+1);
	}
	delete [] huffmantree;
	delete [] code;
	system("pause");
	return 0;
}

void select(const Node huffmantree[],const int num1,int &num2,int &num3)
{
	int i=1;
	while(huffmantree[i].parent!=0)  //���ҵ��������ڵ�Ϊ0�������ڵ� 
		++i;
	num2=i;
	++i;
	while(huffmantree[i].parent!=0)
		++i;
	num3=i;
	++i;
	
	//�����õ�num2<num3 
	if(huffmantree[num2].weight>huffmantree[num3].weight)
	{
		int t=num2;
		num2=num3;
		num3=t;
	}
	//���η������µĽڵ㣬�ҵ�����weight��С�Ľڵ� 
	for(;i<=num1;++i)
	{
		if(huffmantree[i].parent==0)
		{
			if(huffmantree[i].weight<=huffmantree[num2].weight)
			{
				num3=num2;
				num2=i;
			}
			else if(huffmantree[i].weight<huffmantree[num3].weight)
				num3=i;
		}
	}
}
