#include<iostream>

using namespace std;

class project2 {
 	public :int duration;
 	public :double progress;
 	public :string name;
 	public :bool isWeighted;
 	private : string tasksPending[50];
 	private : string tasksCompleted[50];
 	private : int tpSize;
	private :  int tcSize; 	
	
	public : project2(){
		tpSize=0;
		tcSize=0;
	}
	public : project2(string n,bool t){
		tpSize=0;
		tcSize=0;
		name = n;
		isWeighted=t;
	}
	public : project2(string n,bool t,string *a,string *b){
		tpSize=0;
		tcSize=0;
		isWeighted=t;
		name = n;
		*tasksPending=*a;
		*tasksCompleted = *b;
	}
	public : project2(string n,bool t,string *a,string *b,int d){
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
	~project2(){
		cout<<"data of project"<<name <<" deleted\n";
	}

};

project2 compareP(project2 a,project2 b){
	if(a.progress>b.progress){
		return b;
	} else{
		return a;
	}
}
project2 getLeastP(project2 *a,int aSize){
	project2 min = *a;
	for(int i=0;i< aSize;i++){
		if(a->showProgress()<min.showProgress()){
			min=*a;
		}
		a++;
	}	
	return min;
}
project2 getMaxP(project2 *a,int aSize){
	project2 max = *a;
	for(int i=0;i< aSize;i++){
		if(a->showProgress()>max.showProgress()){
			max=*a;
		}
		a++;
	}	
	return max;
}
project2* searchp(project2 *a,int aSize,string n){
	project2 *e;
	for(int i=0;i< aSize;i++){
		if(a->name==n){
			e=a;
		}
		a++;
	}
	return e;
}

			int main(){
				cout << "how many projects do u have \n";
				int x;
				cin >>x;
				 project2 pArr[x];
				 project2 p;
				for(int i=0;i<x;i++){
					cout <<"enter the name of the project :\n";
					string n;
					cin>>n;
					cout <<"does this project "<<n<<" have weighted tasks (N/Y)\n";
					string res;
					cin >>res;
					if(res=="N"){
						pArr[i]=project2(n,false);
					} else if(res=="Y"){
						pArr[i]=project2(n,true);
					}else{
						cout << "invalid input: weight type set to false by default\n";
						pArr[i]=project2(n,false);
					}
					cout << pArr[i].name<<" was added\n";
				}
				 
				int c1=1;
				while(c1!=0){
				int c;
				cout<<"choose command\n";
				cout<<"1) Add Task to project\n";
		 		cout<<"2) complete a task of a project\n";
				cout<<"3) show progress  of a project\n";
				cout<<"4) display pending tasks  of a project\n";
				cout<<"5) display completed tasks  of a project\n";
				cout<<"6) Get project with maximum progress\n";
				cout<<"7) Get project with minimum progress\n";
				cout<<"8) compare progress of two projects\n";
				cout<<"0) end\n";
				cin>>c;
					switch(c) {
					case 8:{
						cout <<"enter name of first project\n";
						string pn1;
						cin>>pn1;
						cout <<"enter name of second project\n";
						string pn2;
						cin>>pn2;
						compareP(*searchp(&pArr[0],x,pn1),*searchp(&pArr[0],x,pn2));
						break;
					}
					case 7:{
						cout <<"project with minimum progress is :"<<getLeastP(&pArr[0],x).name;
						break;
					}
					case 6:{
						cout <<"project with maximum progress is :"<<getMaxP(&pArr[0],x).name;
						break;
					}
			 		case 1:	{
			 			cout <<"enter the project name where the task needs to be added\n";
			 			string pn;
			 			cin >>pn;
			 			cout <<"enter the task name to be added :\n";
			 			string n;
			 			cin>>n;
			 			searchp(&pArr[0],x,pn)->addTask(n);
						break;
					 }
			 		case 2:{
			 			cout <<"enter the project name where the task needs to be completed";
			 			string pn;
			 			cin >>pn;
			 			cout << "enter the task name whichis to be completed :\n";
			 			string n2;
			 			cin>>n2;
			 			searchp(&pArr[0],x,pn)->doneTask(n2);
						break;
					 }
					case 3:{
						cout <<"enter the project name";
			 			string pn;
			 			cin >>pn;
						cout << "current progress is "<<searchp(&pArr[0],x,pn)->showProgress()<<"%";
						break;
					}
						
					case 4:{
						cout <<"enter the project name";
			 			string pn;
			 			cin >>pn;
						searchp(&pArr[0],x,pn)->displayp();
						break;
					}
						
					case 5:{
						cout <<"enter the project name";
			 			string pn;
			 			cin >>pn;
						searchp(&pArr[0],x,pn)->displayc();
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
