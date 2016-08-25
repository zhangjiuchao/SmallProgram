#include<iostream>
#include<cstdlib>

using namespace std;

const double PI=3.14;

class Shape{
	public:
		//把Area()定义为虚函数 
	virtual	double Area(){
	}
};

class Rectangle:public Shape{
	private:
		double lenth,width;
	public:
		Rectangle(){lenth=0;width=0;}
		Rectangle(double L,double W){
			cout<<"The constructor of Retangle is used."<<endl;
			lenth=L;width=W;
		}
		~Rectangle()
		{
			cout<<"The destructor of Rectangle is used."<<endl;
		}
		double Area(){
			return lenth*width;
		}
};


class Round:public Shape{
	private:
		double radius;
	public:
		Round(){radius=0;}
		Round(double r)
		{
			cout<<"The constructor of Round is used."<<endl;		
			radius=r;
		}
		~Round()
		{
			cout<<"The destructor of Round is used."<<endl;
		}
		double Area(){
			return PI*radius*radius;
		}
};

class Square:public Rectangle{
	private:
		double side;
	public:
		Square():Rectangle(0,0){side=0;}
		Square(double a):Rectangle(0,0)
		{
			side=a;
			cout<<"The constructor of Square is used."<<endl;
		}
		
		~Square()
		{
			cout<<"The destructor of Square is used."<<endl;
		}
		double Area(){
			return side*side;
		}
};

int main()
{
	double l,d,r,s,area;
	cout<<"Please input the lenth and width of rectangle:"<<endl;
	cin>>l>>d;
	Rectangle ABCD(l,d);
	area=ABCD.Area();
	cout<<"The area of rectangle ABCD is: "<<area<<endl;
	cout<<"Please input the radius of round."<<endl;
	cin>>r;
	Round RO(r);
	area=RO.Area();
	cout<<"The area of round RO is: "<<area<<endl;
	
	cout<<"Please input the side-long of square abcd:"<<endl;
	cin>>s;
	Square abcd(s);
	area=abcd.Area();
	cout<<"The area of square abcd is: "<<area<<endl;
	
	system("pause");
	return 0;
}

