#include<iostream>
#include<cstdlib>
using namespace std;

//定义Point类 
class Point{
	private:
		int x,y;
	public:
		Point(){x=0;y=0;}
		Point(int ix,int iy){x=ix;y=iy;}
		//重载前置-- 
		Point& operator--(){
			x--;y--;
			return *this;
		}
		//重载前置++ 
		Point& operator++(){
			x++;y++;
			return *this;
		}
		//重载后置-- 
		Point operator--(int){
			Point temp=*this;
			--*this;
			return temp;
		}
		//重载后置++ 
		Point operator++(int){
			Point temp=*this;
			++*this;
			return temp;
		}
		//输出坐标的函数 
		void output(){
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
};
int main()
{
	int X,Y;
	cout<<"Please input the coordinate of point P:"<<endl;
	cin>>X>>Y;
	Point P(X,Y);
	cout<<"P";
	P.output();
	--P;
	cout<<"P1";
	P.output();
	
	++P;
	cout<<"P2";
	P.output();
	
	P--;
	cout<<"P3";
	P.output();
	
	P++;
	cout<<"P4";
	P.output();
	
	
	system("pause");
	return 0;
} 

