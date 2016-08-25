#include<iostream>
#include<thread>
#include<mutex>
#include<time.h>
#include<memory>
using namespace std;

std::mutex m;
int i=100;
auto aa=1;
	
void fun1()
{
	while(1)
	{
		m.lock();
		if(i>0)
		{
			cout<<"fun1 run: "<<i--<<endl;
			m.unlock();
		}
		else
		{
			m.unlock();
			break;
		}	
	}	
}

void fun2()
{
	while(1)
	{
		m.lock();
		if(i>0)
		{
			cout<<"fun2 run: "<<i--<<endl;
			m.unlock();
		}
		else
		{
			m.unlock();
			break;
		}	
	}	
}
main()
{
	
      cout<<aa<<endl;
      thread t1(fun1);
      thread t2(fun2);
      t1.join();
      t2.join();
      return 0;     
}
