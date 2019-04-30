#include<iostream>
#include<cmath>
using namespace std;
class quadratic
{ protected: 
	double a,b,c,x;
	public:
	quadratic()
{		cout<<"enter the value of A, B, C";
		cin>>a>>b>>c;
		x=(b*b)-(4*a*c)	;
		cout<<"the determinant is =\t"<<x<<endl;
}
};

class rur:virtual public quadratic{
public: 
double x1 = a, x2 = b, x3 = c, d = x;
double r1,r2;
public:
	rur()
{
		if(d>0){
		r1=((-x2)-sqrt(d))/2*x1;
		r2=((-x2)+sqrt(d))/2*x1;
		cout<<"the roots are =\t"<<r1<<", "<<r2;	
}
};

class rer:virtual public quadratic{	
public: 
double x1 = a, x2 = b, x3 = c, d = x;
double r3;
public:
	rer()
	{
		if(d==0){
		r3=(-x2)/2*x1;
		cout<<"the roots are =\t"<<r3;	
	}
};
class output:public rur, public rer
{ 	public:
	output(){
	cout << "Calculating quadratic equation";
	}
};

int main()
{ output o1;
return 0;
