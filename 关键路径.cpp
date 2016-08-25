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

//����ʮ������Ļ��ڵ� 
typedef struct arcbox{
	arcbox(int num1=0,int num2=0,int num3=0,struct arcbox *ptab1=NULL,struct arcbox *ptab2=NULL)
	:tailvex(num1),headvex(num2),hlink(ptab1),tlink(ptab2),infor(num3){};
	int tailvex,headvex;
	int infor;
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

stack<int> S,T;
vector<int> ve,vl;

bool TopoSort(OLGraph& G);   //�������� 
void CriticalPath(OLGraph& G);   //��ؼ�·���ĺ��� 
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
		int i=Located(graph,str1);   //���Ӧ���ж϶�λ�Ƿ��ڷ�Χ�ڣ�����Ͳ�д�� 
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

bool TopoSort(OLGraph& G)
{
	int count=0;
	
	//���������Ϊ0�Ķ������ջ��
	for(int i=0;i<G.vexnum;++i)
	{
		if(G.xlist[i].indegree==0)
			S.push(i);
	}
	
	//��ջ��Ϊ��ʱ��ȡջ��Ԫ�أ�����������ҽ���ָ���ͷ������ȼ�1 
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
		fill_n(back_inserter(vl),G.vexnum,ve[G.vexnum-1]);   //��ve�е����һ��ֵ���G.vexnum����vl 
		
		while(!T.empty())        //������˳����ÿ���¼�����ٷ���ʱ�� 
		{
			int num=T.top();
			T.pop();
			ArcBox *nextPtr=G.xlist[num].firstout;
			while(nextPtr!=NULL)
			{
				int k=nextPtr->headvex;
				if(vl[k]-nextPtr->infor<vl[num])           //��ٷ���ʱ����ÿ�������ڵ����ٷ���ʱ���ȥ��Ӧ����ʱ�����Сֵ 
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
				int ee=ve[i],el=vl[k]-dut;      //���¼������緢��ʱ�����ٷ���ʱ�����ʱ��Ϊ�ؼ��¼� 
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


