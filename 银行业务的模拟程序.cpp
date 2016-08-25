#include<iostream>
#include<list>
#include<queue>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int WindowNum= 5;
const int closeTime=1000;
const int ArriveInterval=20;
const int ServeTime=10;
typedef struct event{
	event(int num1,int num2):occurTime(num1),eventType(num2){};
	int occurTime;
	int eventType;
}Event;

typedef struct customer{
	customer(int num1,int num2,int num3):arriveTime(num1),Duration(num2),number(num3){};
	int arriveTime;
	int Duration;
	int number;
}Customer;

int totalTime;
int customerNum;
list<Event> eventList;
queue<Customer> qc[WindowNum+1];
Event en(0,0);
Customer ec(0,0,0);

void openDay();
void CustomerArrive();
void CustomerDeparture();
int minSizeQueue();
class comp:
	public unary_function<Event,bool>
	{
		public:
			comp(int num):newtime(num){};
			bool operator()(const Event& e)
			{
				return e.occurTime>newtime;
			}
		private:
			int newtime;
	};
	

int main()
{
	openDay();
	while(!eventList.empty())
	{
		en=eventList.front();
		eventList.pop_front();
		if(en.eventType==0)
			CustomerArrive();
		else
			CustomerDeparture();
	}
	
	cout<<"The number of customers: "<<customerNum<<endl;
	cout<<"The average time: "<<(float)totalTime/customerNum<<endl;
	system("pause");
	return 0;
}

void openDay()
{
	totalTime=0;
	customerNum=0;
	eventList.push_back(Event(0,0));
}

void CustomerArrive()
{
	++customerNum;
	cout<<"customer "<<customerNum<<" arrive."<<endl; 
	int intertime,dura;
	srand(time(NULL));
	intertime=rand()%ArriveInterval;
	dura=rand()%ServeTime;
	if(en.occurTime+intertime<closeTime)
	{
		Event newevent(en.occurTime+intertime,0);
		list<Event>::iterator it=find_if(eventList.begin(),eventList.end(),comp(newevent.occurTime));	
		eventList.insert(it,newevent);
	}
		
	int num=minSizeQueue();
	qc[num].push(Customer(en.occurTime,dura,customerNum));
	if(qc[num].size()==1)
	{
		Event newevent(en.occurTime+dura,num);
		list<Event>::iterator it=find_if(eventList.begin(),eventList.end(),comp(newevent.occurTime));	
		eventList.insert(it,newevent);
	}
}

void CustomerDeparture()
{
	int i=en.eventType;
	ec=qc[i].front();
	totalTime+=en.occurTime-ec.arriveTime;
	cout<<"customer "<<ec.number<<" depart."<<endl; 
	qc[i].pop();
	if(!qc[i].empty())
	{
		ec=qc[i].front();
		Event newevent(en.occurTime+ec.Duration,i);
		list<Event>::iterator it=find_if(eventList.begin(),eventList.end(),comp(newevent.occurTime));	
		eventList.insert(it,newevent);
	}
}
int minSizeQueue()
{
	int i=1;
	for(int j=2;j<=WindowNum;++j)
	{
		if(qc[i].size()>qc[j].size())
			i=j;
	}
	return i;
}
