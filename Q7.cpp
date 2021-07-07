#include<iostream>
using namespace std;

class task{
public:
int id;
int dur;
int s_Time; //start time of each task
int e_Time; //end time of each task
int* dep; /*list of predecessors of this task - To simplify we assume that a higher number task will
depend on a lower number task e.g. T2 can depend on T1 OR T4 can depend on T2 but the
opposite is not true.*/
int limit;
char skill; //required for PART B
//Resource res; //required for PART B
public:
void addTasks();
void setTaskDuration();//change task duration of all tasks
//set_nth_TaskDuration();//change duration of a specific task
void printTaskDependencyList(task *array,int position_of_task);//print dependencies of a specific task
void setdepended(int limit);
int getid()
{
return this->id;
}
};
void task::setdepended(int limit)
{
dep=new int[limit];
}

void task::addTasks()
{
int limit;
cout<<"Enter the ID:";
cin>>this->id;
cout<<"Enter the duration:";
cin>>this->dur;
cout<<"Enter start time:";
cin>>this->s_Time;
cout<<"Enter end time:";
cin>>e_Time;
cout<<"Enter number of predecessors task (if no predecessors enter 00):";
cin>>limit;
this->limit=limit;
setdepended(limit);

for(int i=0;i<limit;i++)
{
cout<<"PLease enter task "<<i+1<<endl;
cin>>dep[i];
}

}

void task::setTaskDuration()
{

		cout<<"Please enter the new duration of task "<<endl;
		cin>>this->dur;
}


void task::printTaskDependencyList(task *array,int position_of_task)
{
	cout<<"dependencies of a task"<<endl;
	for(int i=0;i<array[position_of_task].limit;i++)
	{
		cout<<array[position_of_task].dur<<endl;
	}	
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
class project{
public:
int id;
int t; //duration of project
task* tasks;
int number_of_tasks;
public:
// provide definitions of following functions...
project();// default constructor

project(task* ts, int n);//initialized the project with n tasks
//you have to implement the following functions
// think about the parameters required and return type of the following functions
void set_nth_TaskDuration();//change duration of a specific task
void completionTime();//print completion time of the project
void printCriticalTasks();/*returns array of critical tasks and displays them – sum of their duration
should be equal to project completion time*/
void completionTimeWithResources();//for PART B

};

project::project()
{
	int number_of_tasks;
	cout<<"Please enter the id of project:";
	cin>>this->id;
	cout<<"Please enter the total time duration of the project:";
	cin>>this->t;
	cout<<"Please enter the number of tasks you want to enter:"<<endl;
	cin>>number_of_tasks;
	this->number_of_tasks=number_of_tasks;
	tasks=new task[number_of_tasks];
}

project::project(task* ts, int n)
{
tasks=new task[n];

//id=ts.getid();
//this->t=ts.t;
this->tasks=ts;


}

void project::set_nth_TaskDuration()
{ int position;
	cout<<"PLease enter the task for changing the duration:";
	cin>>position;
	//cout<<"PLease enter the duration:";
	tasks[position].setTaskDuration();
}


/*void project::completionTime()
{
int end_time;
int position_in_predecessor[3]={999};
//B has predecessor A
//end time of predecessor
//end_time=task[1].dep[1];
//task[1].starttime=task[end_time].endtime;
//check for B in the predecessors list
for(int i=0,j=0;i<number_of_tasks;i++)
{
	if(1==task[i].dep[i])
	{
		position_in_predecessor[j]=i;
		j++;//break;
	}
}
//

}*/


int main()
{
project p;
p.set_nth_TaskDuration();
return 0;
}
