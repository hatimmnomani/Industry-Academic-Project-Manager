#include<iostream>
using namespace std;
class project {
 	private :int duration;
 	public :double progress;
 	private :string name;
 	public :bool isWeigted;
 	private : string tasksPending[];
 	private : string tasksCompleted[];
	 	
	public :void doneTask(string taskName);
 			void makeProgres();
 			double showProgress();
};
