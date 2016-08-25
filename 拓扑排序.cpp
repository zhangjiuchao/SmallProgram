#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
#include<stdexcept> 
/***************************************************************************
 ��������ͨ��ʮ������������ͼ����ͳ�Ƹ���������***********************
 ����ȱ�Ϊ0�Ķ���Ž�ջ�ÿ��ȡջ����Ԫ�ز�������ɴˣ���õ�һ������˳�� 
***************************************************************************/
using namespace std;

const int max_vertex_num=20;

//����ʮ������Ļ��ڵ� 
typedef struct arcbox{
	arcbox(int num1=0,int num2=0,struct arcbox *ptab1=NULL,struct arcbox *ptab2=NULL)
	:tailvex(num1),headvex(num2),hlink(ptab1),tlink(ptab2){};
	int tailvex,headvex;
	struct arcbox *hlink,*tlink;
}ArcBox;

//����ʮ������Ķ���ڵ� 
typedef struct vexnode{
	vexnode(string str="##",int num=0,ArcBox *ptab1=NULL,ArcBox *ptab2=NULL)
	:data(str),indegree(num),firstin(ptab1),firstout(ptab2){};
	string data;
	int indegree;
	ArcBox *firstin,*firstout;
}VexNode;

//����ʮ�����������ͼ 
typedef struct{
	VexNode xlist[max_vertex_num];
	int vexnum,arcnum;
}OLGraph;

void TopoSort(OLGraph& G);   //�������� 

int Located(OLGraph& G,string name);   //��λ��ʶ��Ϊname �Ķ�����ͼ�е�λ�� 

int main()
{
	OLGraph graph;
	string vexname;
	int count=0;
	
	//����ʮ����������ͼ 
	cout<<"Please input the vertices end with '#':"<<endl;
	cin>>vexname;
	while(vexname!="#")
	{
		graph.xlist[count].data=vexname;
		++count;
		cin>>vexname;
	}
	graph.vexnum=count;
	
	count=0;
	cout<<"Please input the arcs(tail front,head follow),end with '# #':"<<endl;
	string str1,str2;
	cin>>str1>>str2;
	while(str1!="#"&&str2!="#")
	{
		++count;
		int i=Located(graph,str1);   //���Ӧ���ж϶�λ�Ƿ��ڷ�Χ�ڣ�����Ͳ�д�� 
		int j=Located(graph,str2);
		try{
			if(i==-1||j==-1)
				throw runtime_error("The arc inputed doesn't exist.");
			ArcBox *newArc=new ArcBox(i,j);
			newArc->tlink=graph.xlist[i].firstout;
			newArc->hlink=graph.xlist[j].firstin;
			++graph.xlist[j].indegree;
			graph.xlist[i].firstout=newArc;
			graph.xlist[j].firstin=newArc;
		}
		catch(runtime_error err){
			cout<<err.what()
				<<"\nPlease input the arc "<<str1<<"-->"<<str2<<" again."<<endl;
		}
		cin>>str1>>str2;
	}
	graph.arcnum=count;
	
	TopoSort(graph);
	
	//�ͷſռ� 
	for(int i=0;i<graph.vexnum;++i)
	{
		ArcBox *nextPtr=graph.xlist[i].firstout;
		ArcBox *temp=nextPtr;
		while(temp!=NULL)
		{
			nextPtr=nextPtr->tlink;
			delete temp;
			temp=nextPtr;
		}
	}
	
	system("pause");
	return 0;
}

void TopoSort(OLGraph& G)
{
	stack<int> myStack;
	int count=0;
	
	//���������Ϊ1�Ķ������ջ�� 
	for(int i=0;i<G.vexnum;++i)
	{
		if(G.xlist[i].indegree==0)
			myStack.push(i);
	}
	
	//��ջ��Ϊ��ʱ��ȡջ��Ԫ�أ�����������ҽ���ָ���ͷ������ȼ�1 
	while(!myStack.empty())
	{
		int top_num=myStack.top();
		myStack.pop();
		cout<<G.xlist[top_num].data<<"->";
		++count;
		ArcBox *nextPtr=G.xlist[top_num].firstout;
		while(nextPtr!=NULL)
		{
			int i=nextPtr->headvex;
			--G.xlist[i].indegree;
			if(G.xlist[i].indegree==0)
				myStack.push(i);
			nextPtr=nextPtr->tlink;
		}
	}
	cout<<"OK"<<endl;
	if(count<G.vexnum)
		cout<<"Toposort unsuccessfully,there is a circuit!!!!!!!!!!!!!"<<endl;
	else
		cout<<"Toposort successfully!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
}

int Located(OLGraph& G,string name)
{
	int i=0;
	for(;i<G.vexnum&&G.xlist[i].data!=name;++i);
	if(i<G.vexnum)
		return i;
	else
		return -1;		
}

