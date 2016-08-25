#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
	int num1,num2;
	cout<<"Please input two integers: ";
	cin>>num1>>num2;
	try{
		if(num2==0)
			throw runtime_error("The divisor can't be 0.");
		cout<<num1/num2<<endl;
		return 0;
	}
	catch(runtime_error err){
		cout<<err.what()<<endl;
	}
}

