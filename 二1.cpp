#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

//�������� 
class Point{
	private:
		double X,Y;
	public:
		double Distance(Point &A);
		//����Point�ĺ������ǹ��캯�������캯�����౻����ʱ�Զ����õģ����㴴�������ʱ������������Ļ��͵��õ�һ��Point,
		//������ô��������������͵��õڶ���Point��������� 
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

//������������ĺ��� 
double Point::Distance(Point &A)
{
	double distance;
	double a,b;
	a=pow(X-A.X,2);b=pow(Y-A.Y,2);
	distance=sqrt(a+b);
	return distance;
}

//��������� 
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

//�����������ĺ��� 
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
	
	Point A(x1,y1),B(x2,y2);//���õڶ���Point����A��B 
	
	Rectangle ABCD(A,B);
	cout<<ABCD.Area()<<endl;
	system("pause");
	return 0;
}

