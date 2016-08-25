#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

/*********************************************************************************************
找出无向图中的关节点，由深度优先生成树可得出两类关节点的特性：********************************
（1）若生成树的根有两棵或两棵以上的子树，则根节点为关节点*************************************
（2）若生成树的某个非叶子节点 V,其某个子树中的所有节点都没有指向 V 的祖先的回边，则 V 为关节点 
*********************************************************************************************/
using namespace std;

const int max_vertex_num=20;    //图中顶点的最大数目 

//定义邻接表中的表节点 
typedef struct arcnode{
	arcnode(int num=0,struct arcnode *pan=NULL):adjvex(num),nextNode(pan){};
	int adjvex;
	struct arcnode *nextNode;
}ArcNode;

//定义邻接表中的头结点 
typedef struct vnode{
	vnode(string str="###",ArcNode *pan=NULL):data(str),firstarc(pan){};
	string data;
	ArcNode *firstarc;
}VNode;

//定义无向图 
typedef struct{
	VNode vertices[max_vertex_num];
	int vexnum,arcnum;
}ALGraph;

void findArticul(ALGraph& G);  //求关节点的函数 

void DFSarticul(ALGraph& G,int v); //递归函数求关节点 

int Located(ALGraph& G,string name);   //定位标识符为name的节点在图中的位置 

int low[max_vertex_num];  //辅助数组，表示与节点i有关联节点中的最先访问次序
 
int visited[max_vertex_num];   //辅助函数，表示节点 i 的访问次序 

int visitCount;   //代表当前访问过的节点数 

int main()
{
	ALGraph graph;
	int arccount=0;
	int vexcount=0;
	string vexname;
	
	/****************************************************************
	*********************构建无向图的邻接表************************** 
	****************************************************************/
	cout<<"Please input the vertices end with '#':"<<endl;
	cin>>vexname;
	while(vexname!="#")
	{
		graph.vertices[vexcount].data=vexname;
		++vexcount;
		cin>>vexname;
	}
	graph.vexnum=vexcount;
	fflush(stdin);
	for(int i=0;i<vexcount;++i)
	{
		cout<<"Please input the vertices related to "<<graph.vertices[i].data<<",end with '#':"<<endl;
		string nodename;
		fflush(stdin);
		cin>>nodename;
		while(nodename!="#")
		{
			int j=Located(graph,nodename);
			if(j==-1)
			{
				cout<<"INPUT ERROR!!!!!"<<endl;
				nodename="#";
				--i;
				continue;
			}
			ArcNode *newarcnode=new ArcNode(j,graph.vertices[i].firstarc);
			graph.vertices[i].firstarc=newarcnode;
			++arccount;
			cin>>nodename;
		}
	}
	graph.arcnum=arccount/2;
	
	findArticul(graph);
	
	/**********************************************
	********************释放空间*******************
	**********************************************/ 
	for(int i=0;i<graph.vexnum;++i)
	{
		ArcNode *next=graph.vertices[i].firstarc;
		ArcNode *temp=next;
		while(temp!=NULL)
		{
			next=next->nextNode;
			delete temp;
			temp=next;
		}
	}
	system("pause");
	return 0;
}

void findArticul(ALGraph& G)
{
	visitCount=1;
	visited[0]=1;
	for(int i=1;i<G.vexnum;++i)
		visited[i]=0;
	ArcNode *pt=G.vertices[0].firstarc;
	int k=pt->adjvex;
	DFSarticul(G,k);
	if(visitCount<G.vexnum)   //如果满足条件，则代表根不止一棵子树 
	{
		cout<<G.vertices[0].data<<" is a articulation point."<<endl;
		for(ArcNode *nextPtr=pt->nextNode;nextPtr!=NULL;nextPtr=nextPtr->nextNode)
		{
			int v=nextPtr->adjvex;
			if(visited[v]==0)
				DFSarticul(G,v);
		}
	}
}

void DFSarticul(ALGraph& G,int v)
{
	++visitCount;
	visited[v]=visitCount;
	int min=visitCount;
	//访问 V 的所有邻接顶点 
	for(ArcNode *nextPtr=G.vertices[v].firstarc;nextPtr!=NULL;nextPtr=nextPtr->nextNode)
	{
		int i=nextPtr->adjvex;
		if(visited[i]==0)
		{
			DFSarticul(G,i);
			if(low[i]<min)
				min=low[i];
			if(low[i]>=visited[v])
				cout<<G.vertices[v].data<<" is a articulation point."<<endl;
		}
		else if(visited[i]<min)
				min=visited[i];		
	}
	low[v]=min;
}

int Located(ALGraph& G,string name)
{
	int i=0;
	for(;i<G.vexnum&&G.vertices[i].data!=name;++i);
	if(i<G.vexnum)
		return i;
	else
		return -1;		
}

