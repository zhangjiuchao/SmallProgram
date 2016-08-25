#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
#include<stdexcept> 
/***************************************************************************
 拓扑排序，通过十字链表构建有向图，并统计各顶点的入度***********************
 将入度变为0的顶点放进栈里，每次取栈顶的元素并输出。由此，便得到一个拓扑顺序 
***************************************************************************/
using namespace std;

const int max_vertex_num=20;

//定义十字链表的弧节点 
typedef struct arcbox{
	arcbox(int num1=0,int num2=0,struct arcbox *ptab1=NULL,struct arcbox *ptab2=NULL)
	:tailvex(num1),headvex(num2),hlink(ptab1),tlink(ptab2){};
	int tailvex,headvex;
	struct arcbox *hlink,*tlink;
}ArcBox;

//定义十字链表的顶点节点 
typedef struct vexnode{
	vexnode(string str="##",int num=0,ArcBox *ptab1=NULL,ArcBox *ptab2=NULL)
	:data(str),indegree(num),firstin(ptab1),firstout(ptab2){};
	string data;
	int indegree;
	ArcBox *firstin,*firstout;
}VexNode;

//定义十字链表的有向图 
typedef struct{
	VexNode xlist[max_vertex_num];
	int vexnum,arcnum;
}OLGraph;

void TopoSort(OLGraph& G);   //拓扑排序 

int Located(OLGraph& G,string name);   //定位标识符为name 的顶点在图中的位置 

int main()
{
	OLGraph graph;
	string vexname;
	int count=0;
	
	//构建十字链表有向图 
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
		int i=Located(graph,str1);   //这儿应该判断定位是否在范围内，这儿就不写了 
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
	
	//释放空间 
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
	
	//将所有入度为1的顶点放入栈中 
	for(int i=0;i<G.vexnum;++i)
	{
		if(G.xlist[i].indegree==0)
			myStack.push(i);
	}
	
	//当栈不为空时，取栈顶元素，并输出。并且将弧指向的头结点的入度减1 
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

