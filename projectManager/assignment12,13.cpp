#include<iostream>

using namespace std;

class project2 {
 	public :int duration;
 	public :double progress;
 	public :string name;
 	public :bool isWeighted;
 	public : string tasksPending[50];
 	public : string tasksCompleted[50];
 	public : int tpSize;
	public :  int tcSize; 	
	
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
	public :project2 operator+(project2& b){
		for(int i=0;i<b.getcs();i++){
			tasksCompleted[i+getcs()]=b.tasksCompleted[i];
		}
		for(int i=0;i<b.getps();i++){
			tasksPending[i+getps()]=b.tasksPending[i];
		}
		return *this;
	}
	~project2(){
		cout<<"data of project"<<name <<" deleted\n";
	}

};
class IndustryProject: virtual public project2{
	string  projectManager;
	int daysDueBy;
	double revenue;
	public: IndustryProject(){
		tpSize=0;
		tcSize=0;
	}
	public: IndustryProject(string n,bool t,string pm,int dt,double rev){
		tpSize=0;
		tcSize=0;
		name = n;
		isWeighted=t;
		projectManager =pm;
		daysDueBy=dt;
		revenue = rev;
	}
	public: double getValuePerTask(){
		return (tpSize+tcSize)/revenue;
	}
	public :IndustryProject operator+(IndustryProject& b){
		for(int i=0;i<b.getcs();i++){
			tasksCompleted[i+getcs()]=b.tasksCompleted[i];
		}
		for(int i=0;i<b.getps();i++){
			tasksPending[i+getps()]=b.tasksPending[i];
		}
		return *this;
	}
	 
};
class AcademicProject: public project2{
	string  professorName;
	int daysDueBy;
	double credits;
	public: AcademicProject(){
		tpSize=0;
		tcSize=0;
	}
	public: AcademicProject(string n,bool t,string pm,int dt,double rev){
		tpSize=0;
		tcSize=0;
		name = n;
		isWeighted=t;
		professorName =pm;
		daysDueBy=dt;
		credits = rev;
	}
	public: double getCreditsPerTask(){
		return (tpSize+tcSize)/credits;
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
IndustryProject* searchp(IndustryProject *a,int aSize,string n){
	IndustryProject *e;
	for(int i=0;i< aSize;i++){
		if(a->name==n){
			e=a;
		}
		a++;
	}
	return e;
}
AcademicProject* searchap(AcademicProject *a,int aSize,string n){
	AcademicProject *e;
	for(int i=0;i< aSize;i++){
		if(a->name==n){
			e=a;
		}
		a++;
	}
	return e;
}


			int main(){
				cout << "how many Industry projects do u have \n";
				int x;
				cin >>x;
				cout << "how many Academic projects do u have \n";
				int y;
				cin >>y;
				// project2 pArr[x];
				IndustryProject pArr[x];
				 AcademicProject aArr[y];
				 
				for(int i=0;i<x;i++){
					cout <<"enter the name of the Industry project :\n";
					string n;
					cin>>n;
					cout <<"enter the name of the project manager :\n";
					string m;
					cin>>m;
					cout <<"enter the number of days by which the project is due :\n";
					int o;
					cin>>o;
					cout <<"enter the value for the Industry project :\n";
					double p;
					cin>>p;
					cout <<"does this project "<<n<<" have weighted tasks (N/Y)\n";
					string res;
					cin >>res;
					if(res=="N"){
						pArr[i]=IndustryProject(n,false,m,o,p);
					} else if(res=="Y"){
						pArr[i]=IndustryProject(n,true,m,o,p);
					}else{
						cout << "invalid input: weight type set to false by default\n";
						pArr[i]=IndustryProject(n,false,m,o,p);
					}
					cout << pArr[i].name<<" was added\n";
				}
				for(int i=0;i<y;i++){
					cout <<"enter the name of the Academic project :\n";
					string n;
					cin>>n;
					cout <<"enter the name of the professor :\n";
					string m;
					cin>>m;
					cout <<"enter the number of days by which the project is due :\n";
					int o;
					cin>>o;
					cout <<"enter the credits for the Academic project :\n";
					double p;
					cin>>p;
					cout <<"does this project "<<n<<" have weighted tasks (N/Y)\n";
					string res;
					cin >>res;
					if(res=="N"){
						pArr[i]=IndustryProject(n,false,m,o,p);
					} else if(res=="Y"){
						pArr[i]=IndustryProject(n,true,m,o,p);
					}else{
						cout << "invalid input: weight type set to false by default\n";
						pArr[i]=IndustryProject(n,false,m,o,p);
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
				cout<<"9) merge two projects\n";
				cout<<"10) get value per task for Industry Project\n";
				cout<<"11) get credits per task for Academic Project\n";
				cout<<"0) end\n";
				cin>>c;
					switch(c) {
					case 11:{
						cout<<"enter name of Academic project";
						string ipn;
						cin>>ipn;
						cout<<"credits per task is :"<<searchap(&aArr[0],y,ipn)->getCreditsPerTask();
						break;
					}
					case 10:{
						cout<<"enter name of Industry project";
						string ipn;
						cin>>ipn;
						cout<<"valus per task is :"<<searchp(&pArr[0],x,ipn)->getValuePerTask();
						break;
					}
					case 9:{
						cout <<"enter name of first project\n";
						string pn1;
						cin>>pn1;
						cout <<"enter name of second project\n";
						string pn2;
						*searchp(&pArr[0],x,pn1)=*searchp(&pArr[0],x,pn1)+*searchp(&pArr[0],x,pn2);
						break;
					}
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
