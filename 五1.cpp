#include<iostream>
#include<cstdlib>
using namespace std;

//����Point�� 
class Point{
	private:
		int x,y;
	public:
		Point(){x=0;y=0;}
		Point(int ix,int iy){x=ix;y=iy;}
		//����ǰ��-- 
		Point& operator--(){
			x--;y--;
			return *this;
		}
		//����ǰ��++ 
		Point& operator++(){
			x++;y++;
			return *this;
		}
		//���غ���-- 
		Point operator--(int){
			Point temp=*this;
			--*this;
			return temp;
		}
		//���غ���++ 
		Point operator++(int){
			Point temp=*this;
			++*this;
			return temp;
		}
		//�������ĺ��� 
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

