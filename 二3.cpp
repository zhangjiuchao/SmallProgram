#include<iostream>
#include<cstdlib>
using namespace std;

class Car;//����Car�� 

//����Boat�� 
class Boat{
public:
	Boat(double W){weight=W;}
	friend double
	TotalWeight(Boat& b,Car& c);//������Ԫ���� 
private:
	double weight;
	
};

class Car{
	friend double
	TotalWeight(Boat& b,Car& c);//������Ԫ���� 
	
	private:
		double weight;
	public:
		Car(double W){weight=W;}
};

//
double TotalWeight(Boat& b,Car& c)
{
	double Tweight;
	Tweight=b.weight+c.weight;
	return Tweight;
}

int main()
{
	double Bweight,Cweight; 
	
	cout<<"Please input weight of boat and car."<<endl;
	
	cin>>Bweight>>Cweight;
	
	Boat B(Bweight);//����Boat������Car����
	Car C(Cweight);
	
	Boat &rB=B;
	Car &rC=C;
	
	double tatol_weight;
	tatol_weight=TotalWeight(rB,rC);
	cout<<"The tatol weight of boat and car is "<<tatol_weight<<"."<<endl;
	system("pause");
	return 0;
}

