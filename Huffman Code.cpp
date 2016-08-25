#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<iterator>
using namespace std;
//定义树节点 
typedef struct node{
	node(){};
	node(float num1,int num2,int num3,int num4):weight(num1),parent(num2),lchild(num3),rchild(num4){};
	float weight;
	int parent,lchild,rchild;
}Node;

void select(const Node huffmantree[],const int num1,int &num2,int &num3); //挑选已有节点中weight 最小的两个节点 

int main()
{
	float num;
	int count;
	cout<<"Please input the number: ";  //输入字符的个数 
	cin>>count;
	Node *huffmantree=new Node [2*count];
	if(!huffmantree) cerr<<"ERROE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	cout<<"Please input the weights:"<<endl;   //输入权重 
	int i=1;
	//构造输入的叶子节点 
	for(;i<=count;++i)
	{
		cin>>num;
		huffmantree[i]=Node(num,0,0,0);
	}
	//构造需要的中间节点 
	for(;i<=2*count-1;++i)
		huffmantree[i]=Node(0,0,0,0);
	int j;
	
	//构造huffmantree 
	for(int k=count+1;k<=2*count-1;++k)
	{
		select(huffmantree,k-1,i,j);
		huffmantree[i].parent=k;
		huffmantree[j].parent=k;
		huffmantree[k].lchild=i;
		huffmantree[k].rchild=j;
		huffmantree[k].weight=huffmantree[i].weight+huffmantree[j].weight;
	}
	
	char *code=new char[count+2];  //存放编码的数组
	code[count+1]='\0';
	//从叶子节点访问到根节点，求得每个字符的哈弗曼编码，左孩子为0，右孩子为1
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
	while(huffmantree[i].parent!=0)  //先找到两个父节点为0的两个节点 
		++i;
	num2=i;
	++i;
	while(huffmantree[i].parent!=0)
		++i;
	num3=i;
	++i;
	
	//操作得到num2<num3 
	if(huffmantree[num2].weight>huffmantree[num3].weight)
	{
		int t=num2;
		num2=num3;
		num3=t;
	}
	//依次访问余下的节点，找到两个weight最小的节点 
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
