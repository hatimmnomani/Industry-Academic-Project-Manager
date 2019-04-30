#include<iostream>
using namespace std;
class project {
 	private :int duration;
 	public :double progress=0.0;
 	private :string name;
	 	
	public: project(string n,int d){
		name = n;
		duration=d;
	}
	public :string getName(){
		return name;
	}
 	public: void progres(){
 		progress+=10;
	 }
};

int main() {
	cout<< "\t\tEnter Project name :\t";
	string n;
	cin>>n;
	int l;
	cout<< "\n\t\tIn how many days you have to complete this project:\t";
	cin>>l;
	project x1(n,l);
	bool t=true;
	while(t){
		int c;
		cout<<"\n\n\t\t 1) display project ";
		cout<<"\n\t\t 2) Make progress in project ";
		cout<<"\n\t\t 0) Exit ";
		cin>>c;
		if(c==0){
			t=false;
		} else if(c==1){
			cout<< "\n\t\t Name: "<<x1.getName();
			cout<< "\n\t\t Status: "<<x1.progress<<"% completed";
		}
		else if(c==2){
			x1.progres();
			cout<< "\n\t\tprogress made!";
		}
	}
	return 0;
}
