#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

//定义点的类 
class Point{
	private:
		double X,Y;
	public:
		double Distance(Point &A);
		//两个Point的函数都是构造函数，构造函数在类被创建时自动调用的，当你创建类对象时，不传入参数的话就调用第一个Point,
		//如果调用传入两个参数，就调用第二个Point构造类对象 
		Point()
		{
			X=0;Y=0;
		}
		Point(double x1,double y1)
		{
			X=x1;Y=y1;
		}
		
		double GetX(){return X;}
		double GetY(){return Y;}
};

//计算两点间距离的函数 
double Point::Distance(Point &A)
{
	double distance;
	double a,b;
	a=pow(X-A.X,2);b=pow(Y-A.Y,2);
	distance=sqrt(a+b);
	return distance;
}

//定义矩形类 
class Rectangle{
	private:
		Point p1,p2;
	public:
		Rectangle(Point &A,Point &B)
		{
			p1=A;p2=B;
		}
		double Area();
};

//计算矩形面积的函数 
double Rectangle::Area()
{
	double x,y;
	x=p1.GetX();y=p2.GetY();
	Point C(x,y);
	double distance1,distance2;
	distance1=p1.Distance(C);
	distance2=p2.Distance(C);
	double area=distance1*distance2;
	return area;
}


int main()
{
	double x1,y1,x2,y2;
	
	cout<<"Please input two coordinates(left-up and right-down) of a rectangle."<<endl;
	cin>>x1>>y1>>x2>>y2;
	
	Point A(x1,y1),B(x2,y2);//调用第二个Point构造A，B 
	
	Rectangle ABCD(A,B);
	cout<<ABCD.Area()<<endl;
	system("pause");
	return 0;
}

