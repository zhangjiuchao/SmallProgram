#include<iostream>
#include<cstdlib>
#include<stack>
#include<string>
#include<stdexcept>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

const int max_vertex_num=20;

//定义十字链表的弧节点 
typedef struct arcbox{
	arcbox(int num1=0,int num2=0,int num3=0,struct arcbox *ptab1=NULL,struct arcbox *ptab2=NULL)
	:tailvex(num1),headvex(num2),hlink(ptab1),tlink(ptab2),infor(num3){};
	int tailvex,headvex;
	int infor;
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

stack<int> S,T;
vector<int> ve,vl;

bool TopoSort(OLGraph& G);   //拓扑排序 
void CriticalPath(OLGraph& G);   //求关键路径的函数 
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
		ve.push_back(0);
		cin>>vexname;
	}
	graph.vexnum=count;
	
	count=0;
	cout<<"Please input the arcs(tail front,head follow),end with '# #':"<<endl;
	string str1,str2;
	int ArcLenth;
	cin>>str1>>str2>>ArcLenth;
	while(ArcLenth!=0)
	{
		++count;
		int i=Located(graph,str1);   //这儿应该判断定位是否在范围内，这儿就不写了 
		int j=Located(graph,str2);
		try{
			if(i==-1||j==-1)
				throw runtime_error("The arc inputed doesn't exist.");
			ArcBox *newArc=new ArcBox(i,j,ArcLenth);
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
		cin>>str1>>str2>>ArcLenth;
	}
	graph.arcnum=count;
	
	CriticalPath(graph);
		
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

bool TopoSort(OLGraph& G)
{
	int count=0;
	
	//将所有入度为0的顶点放入栈中
	for(int i=0;i<G.vexnum;++i)
	{
		if(G.xlist[i].indegree==0)
			S.push(i);
	}
	
	//当栈不为空时，取栈顶元素，并输出。并且将弧指向的头结点的入度减1 
	while(!S.empty())
	{
		int top_num=S.top();
		S.pop();
		T.push(top_num);
		++count;
		ArcBox *nextPtr=G.xlist[top_num].firstout;
		while(nextPtr!=NULL)
		{
			int i=nextPtr->headvex;
			--G.xlist[i].indegree;
			if(G.xlist[i].indegree==0)
				S.push(i);
			if(ve[top_num]+nextPtr->infor>ve[i])
				ve[i]=ve[top_num]+nextPtr->infor;
			nextPtr=nextPtr->tlink;
		}
	}
	if(count<G.vexnum)
		return false;
	else
		return true;
}
void CriticalPath(OLGraph& G)
{
	if(!TopoSort(G))
		cout<<"There is a circuit.";
	else
	{	
		fill_n(back_inserter(vl),G.vexnum,ve[G.vexnum-1]);   //将ve中的最后一个值填充G.vexnum个进vl 
		
		while(!T.empty())        //反拓扑顺序求每个事件的最迟发生时间 
		{
			int num=T.top();
			T.pop();
			ArcBox *nextPtr=G.xlist[num].firstout;
			while(nextPtr!=NULL)
			{
				int k=nextPtr->headvex;
				if(vl[k]-nextPtr->infor<vl[num])           //最迟发生时间是每个后续节点的最迟发生时间减去相应弧的时间的最小值 
					vl[num]=vl[k]-nextPtr->infor;
				nextPtr=nextPtr->tlink;
			}
		}

		for(int i=0;i<G.vexnum;++i)
		{
			ArcBox *nextPtr=G.xlist[i].firstout;
			while(nextPtr!=NULL)
			{
				int k=nextPtr->headvex;
				int dut=nextPtr->infor;
				int ee=ve[i],el=vl[k]-dut;      //当事件的最早发生时间和最迟发生时间相等时，为关键事件 
				if(ee==el)
					cout<<G.xlist[i].data<<"->"<<G.xlist[k].data<<" "<<dut<<endl;
				nextPtr=nextPtr->tlink;
			}
		}
	}
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


