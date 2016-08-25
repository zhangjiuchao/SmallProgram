#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>

/*********************************************************************************************
�ҳ�����ͼ�еĹؽڵ㣬����������������ɵó�����ؽڵ�����ԣ�********************************
��1�����������ĸ������û��������ϵ�����������ڵ�Ϊ�ؽڵ�*************************************
��2������������ĳ����Ҷ�ӽڵ� V,��ĳ�������е����нڵ㶼û��ָ�� V �����ȵĻرߣ��� V Ϊ�ؽڵ� 
*********************************************************************************************/
using namespace std;

const int max_vertex_num=20;    //ͼ�ж���������Ŀ 

//�����ڽӱ��еı�ڵ� 
typedef struct arcnode{
	arcnode(int num=0,struct arcnode *pan=NULL):adjvex(num),nextNode(pan){};
	int adjvex;
	struct arcnode *nextNode;
}ArcNode;

//�����ڽӱ��е�ͷ��� 
typedef struct vnode{
	vnode(string str="###",ArcNode *pan=NULL):data(str),firstarc(pan){};
	string data;
	ArcNode *firstarc;
}VNode;

//��������ͼ 
typedef struct{
	VNode vertices[max_vertex_num];
	int vexnum,arcnum;
}ALGraph;

void findArticul(ALGraph& G);  //��ؽڵ�ĺ��� 

void DFSarticul(ALGraph& G,int v); //�ݹ麯����ؽڵ� 

int Located(ALGraph& G,string name);   //��λ��ʶ��Ϊname�Ľڵ���ͼ�е�λ�� 

int low[max_vertex_num];  //�������飬��ʾ��ڵ�i�й����ڵ��е����ȷ��ʴ���
 
int visited[max_vertex_num];   //������������ʾ�ڵ� i �ķ��ʴ��� 

int visitCount;   //����ǰ���ʹ��Ľڵ��� 

int main()
{
	ALGraph graph;
	int arccount=0;
	int vexcount=0;
	string vexname;
	
	/****************************************************************
	*********************��������ͼ���ڽӱ�************************** 
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
	********************�ͷſռ�*******************
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
	if(visitCount<G.vexnum)   //���������������������ֹһ������ 
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
	//���� V �������ڽӶ��� 
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

