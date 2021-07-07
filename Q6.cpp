#include<iostream>
using namespace std;

struct Runway {
int id;
string type;
bool availability;
int dur;
int s_Time; //start time of each task

public:
bool getstatus();
void assignrunway();
void setstatus(bool a);
};
void Runway::assignrunway()
{
cout<<"Please Enter Run Way id: ";
cin>>id;
cout<<"Please enter type";
cin>>type;
cout<<"Please enter availability";
cin>>availability;
cout<<"PLease enter the duration:";
cin>>dur;
cout<<"PLease enter Starting Time:";
cin>>s_Time;

}

bool Runway::getstatus()
{
	return availability;
}

void Runway::setstatus(bool a)
{
this->availability=a;
}

class Flight{
private:
// think about the private data members...
string flight_No; //
double arrivalTime; //arrival time which is known at the departure.
double remaingFlyTime; //how long can the fuel last it no runway is available
double scheduled_landing_Time; //
Runway rn; //
public:
// constructors
// provide definitions of following functions...
void addFlight(); //function to add flight information
void UpdateRemainingFlyTime(); //This is updated once the flight contacts AirController
void UpdateLandingInfo(double updated_time,Runway r); //get landing time from the AirController depending on the availability of the runway
void Display();
};

void Flight::addFlight()
{
cout<<"**********************Please enter flight info********************************\n";
	cout<<"Please enter flight number:\n";
	cin>>flight_No;
	cout<<"Please enter arrival time:\n";
	cin>>arrivalTime;
	cout<<"Please enter remaining FlyTime:\n";
	cin>>remaingFlyTime;
	cout<<"Please enter schediled landing time:\n";
	cin>>scheduled_landing_Time;
	
}

void Flight::Display()
{
	cout<<"Flight NUmber:"<<flight_No<<endl;
	cout<<"Arrival Time:"<<arrivalTime<<endl;
	cout<<"Remaining Fly TIme:"<<remaingFlyTime<<endl;
	cout<<"Landing Time:"<<scheduled_landing_Time<<endl;

}
void Flight::UpdateRemainingFlyTime()
{
double current_time;	
	cout<<"Enter current time\n";
	cin>>current_time;
	this->remaingFlyTime=arrivalTime-current_time;
}
void Flight::UpdateLandingInfo(double updated_time,Runway r)
{

	this->rn=r;
	this->scheduled_landing_Time-updated_time;
}



class AirController {
private:
// think about the private data members...
Runway *runway;
Flight *flights;
int total_flights;
public:
// constructors
AirController();
// provide definitions of following functions...
/*Special class with only one instance during execution of the program, there is only air traffic
controller and landing time is allocated to plans in a centralized fashion*/
bool RunwayStatus(int i);//prints the status of all the runways
void FlightContact(); //prints the data of flights who have contacted the controller
void AssignRunway(int);//assigns runway to a flight
void setlanding(int time,int r,int f);

};
AirController::AirController()
{
cout<<"PLease enter total number of flights:\n";
cin>>total_flights;
runway=new Runway[3];
flights=new Flight[total_flights];

for(int i=0;i<3;i++)
{
cout<<"Enter data of RunWay "<<i+1<<":\n";
runway[i].assignrunway();
}
}


bool AirController::RunwayStatus(int i)
{
	
		//cout<<"Runway "<<i+1<<" :";
		//cout<<runway[i].getstatus()<<endl;
		return runway[i].getstatus();
}

void AirController::FlightContact()
{
	for(int i=0;i<total_flights;i++)
	{
		flights[i].addFlight();
	}
	for(int i=0;i<total_flights;i++)
	{	cout<<endl<<"Flight :"<<i+1<<endl;
		flights[i].Display();
	}

}

void AirController::AssignRunway(int flight_number)
{double time;
	//for(int i=0;i<5;i++)
		for(int i=0;i<3;i++)
		{
			if(runway[i].getstatus()==true)
			{	
				cout<<"Please enter the current time:\n";
				cin>>time;
				flights[flight_number].UpdateLandingInfo(time,runway[i]);
				runway[i].setstatus(false);
				cout<<"Runway assigned\n";
			}
			else
			{
				cout<<"Runway "<<i+1<<" is not avaliable!\n";
			}
		}

	
}

void AirController::setlanding(int time,int r,int f)
{
	flights[f].UpdateLandingInfo(time,runway[r]);
}
int main()
{
int option=99;
cout<<"**********************WELCOME**********************\n";

AirController air_controller;

air_controller.FlightContact();
while(option!=0)
{
cout<<"What do you want to do?\n";
cout<<"0.Exit\n1.Check Runway Status\n2.Assign Runway\n3.Update Landing info";
cin>>option;
switch(option)
{
	case 0:
	{
		break;
	}
	case 1:
	{	int runway_id;
		cout<<"Please enter the runway id to get the status\n";
		cin>>runway_id;
		if(air_controller.RunwayStatus(runway_id)==1)
		{
			cout<<"Runway is avaliable\n";
			break;
		}
		else

		{
			cout<<"Runway is not avaliable\n";
			break;
		}
		break;
	}
	case 2:
	{	int flight_number;
		cout<<"Please enter the flight number to assign the runway:\n";
		cin>>flight_number;
		air_controller.AssignRunway(flight_number);
		break;
	}
	case 3:
	{	
		int runway_num;
		double current_time;
		int flight_number;
		cout<<"Please enter the flight number to assign the runway:\n";
		cin>>flight_number;
		cout<<"PLease enter the avaliable runway:\n";
		cin>>runway_num;
		cout<<"Please enter the current time\n";
		cin>>current_time;
		air_controller.setlanding(current_time,runway_num,flight_number);
		cout<<"Updated!!\n";
	}

}
}
return 0;
}
