#include<iostream>
using namespace std;
class gcd{
	private: int n1;
	private: int n2;
	//private: tn;
	public: gcd(){
		cout << "enter first number ";
		int a;
		cin>>a;
		n1=a;
		cout << "enter second number ";
		int b;
		cin>>b;
		n1=b;
	}
	public: double gcdCalc(){
		int temp;
		int a =n1;
		int b =n2;
		if(a>b){
			temp=a;
			a=b;
			b=temp;
		}
		while(a!=0){
			temp=a;
			a = b%a;
			b=temp;
		}
		return b;
	}
};
int main(){
	gcd c;
	cout<<"gcd calculation equals to: "<<c.gcdCalc();
}
