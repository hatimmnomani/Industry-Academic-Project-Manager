#include<iostream>

using namespace std;

class project1 {
 	public :int duration;
 	public :double progress;
 	public :string name;
 	public :bool isWeighted;
 	private : string tasksPending[50];
 	private : string tasksCompleted[50];
 	private : int tpSize;
	private :  int tcSize; 	
	
	public : project1(){
		tpSize=0;
		tcSize=0;
	}
	public : project1(string n,bool t){
		tpSize=0;
		tcSize=0;
		name = n;
		isWeighted=t;
	}
	public : project1(string n,bool t,string *a,string *b){
		tpSize=0;
		tcSize=0;
		isWeighted=t;
		name = n;
		*tasksPending=*a;
		*tasksCompleted = *b;
	}
	public : project1(string n,bool t,string *a,string *b,int d){
		tpSize=0;
		tcSize=0;
		isWeighted=t;
		name = n;
		*tasksPending=*a;
		*tasksCompleted = *b;
		duration = d;
	}
	public :void doneTask(string taskName){
				for(int i =0;i<tpSize;i++) {
					if(tasksPending[i]==taskName){
						cout<<"\ntask :"<<tasksPending[i]<<"is completed";
						for(int j=i;j<tpSize-1;j++){
							tasksPending[i]=tasksPending[i+1];
						}
						tpSize--;
						tasksCompleted[tcSize]=taskName;
						tcSize++;
						return;
					}
				}
				cout<<"Task not found Therefore cannot be completed";
			}
 			
 	public :int getps(){
			 return tpSize;
			 }
			 int getcs(){
			 return tcSize;
			 }
	public :double showProgress(){
				if(tcSize!=0 && tpSize!= 0){
					return (tcSize*100)/tpSize;	
				}
				else if(tpSize==0){
					return 100.00;
				}
				else{
					return 0.00;
				}
				
				
			}
		 	
	public :void addTask(string taskName){
			//cout<<"hii";
				tasksPending[tpSize]=taskName;
				tpSize++;
			//cout<<"h2";
			}
	public :void displayp(){
				for(int i= 0;i<getps();i++){
							cout <<tasksPending[i]<<"\n";
						}
			}
	public :void displayc(){
				for(int i= 0;i<getcs();i++){
							cout <<tasksCompleted[i]<<"\n";
						}
			}
	~project1(){
		cout<<"data of project"<<name <<" deleted\n";
	}

};
			int main(){
				 project1 p;
				int c1=1;
				while(c1!=0){
				int c;
				cout<<"choose command";
				cout<<"1) Add Task\n";
		 		cout<<"2) complete a task\n";
				cout<<"3) show progress\n";
				cout<<"4) display pending tasks\n";
				cout<<"5) display completed tasks\n";
				cout<<"0) end\n";
				cin>>c;
				
					switch(c) {
			 		case 1:	{
			 			cout <<"enter the task name to be added :\n";
			 			string n;
			 			cin>>n;
			 			p.addTask(n);
						break;
					 }
			 		case 2:{
			 			cout << "enter the task name whichis tobe completed :\n";
			 			string n2;
			 			cin>>n2;
			 			p.doneTask(n2);
						break;
					 }
					case 3:{
						cout << "current progress is "<<p.showProgress()<<"%";
						break;
					}
						
					case 4:{
						p.displayp();
						break;
					}
						
					case 5:{
						p.displayc();
						break;
					}
					case 0:{
						c1=0;
						break;
					}
						
					default:
						cout <<"not a valid command";
					}
				}
		 		return 0;
			 }
