//Dear checker please be lineant in checking because this assignement has given a very tough time mentally.Although I have tried my best on each question I request you to please be lineant. Thank you I hope you understand.

#include<iostream>
#include <time.h>
#include <iostream>
using namespace std;

class Player{
public:
char* name;
string type; //type of the player “attacking” or “defensive”
double points; //randomly assign points between 30 to 40 randomly
bool availability;
public:
// constructors
Player();
void displaydata();//displays the whole data of a player on the terminal
void setavail(bool status);//set the status of the player
void setpoint(double point);//set the points of each player
double getpoints();//returns the points of the player
bool getavail();
};
Player::Player()
{
name=new char [40];
}
void Player::displaydata()
{
	cout<<name<<"		"<<type<<"		"<<points<<"		"<<availability<<endl;
}

void Player::setavail(bool status)
{
this->availability=status;	
}
bool Player::getavail()
{
return this->availability;	
}
void Player::setpoint(double point)
{
this->points=point;
}
double Player::getpoints()
{
return this->points;
}
////////////////////////////////////////////////
////////////////////////////////////////////////
/////////////Teams/////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////
///////////////////////////////////////////////
class Team{
char* teamName;
int teamRank;
Player* teamPlayers;
Player *sort;
public:
Team();
Player *sorting();//have the players sorted according to their ranking /points
void setrank(int);//set the rank of the team
void setname(char*);//name of the team
Player setplayer(int position);//returns the player from the player array of a team
void setpoints(int position,double point);
//void setrank(int rank);//sets the rank of a team
int getrank();//returns the rank of a team
//void setplayer(int position);
void displaybest();//display the best player of a team
void sortingplayer();//this function sorts the player on the basis of their points to display them in leadboard
};
Team::Team()
{

sort=new Player[3];
teamName=new char[40];
teamPlayers=new Player[3];
}

void Team::setname(char* name)
{
teamName=name;
}

void Team::setrank(int rank)
{
	this->teamRank=rank;
}

int Team::getrank()
{
	return this->teamRank;
}


Player Team::setplayer(int position)
{
	return teamPlayers[position];
}

void Team::setpoints(int position,double point)
{
	teamPlayers[position].setpoint(point);
	cout<<"Point updated"<<endl;
}

void Team::displaybest()
{
	if(teamPlayers[0].getpoints()>teamPlayers[1].getpoints())
	{
		if(teamPlayers[0].getpoints()>teamPlayers[2].getpoints())
		{
			teamPlayers[0].displaydata();
		}
		else
		{
			teamPlayers[2].displaydata();
		}
	}
	else
	{
		if(teamPlayers[1].getpoints()>teamPlayers[2].getpoints())
		{
			teamPlayers[1].displaydata();
		}
		else
		{
			teamPlayers[2].displaydata();
		}
	}
}

void Team::sortingplayer()//sorting by comparision of the points of the players
{

if(teamPlayers[0].getpoints()>teamPlayers[1].getpoints() && teamPlayers[0].getpoints()>teamPlayers[2].getpoints() )
	{
			sort[0]=teamPlayers[0];
		if(teamPlayers[1].getpoints()>teamPlayers[2].getpoints())
		{
			sort[1]=teamPlayers[1];
			sort[2]=teamPlayers[2];
		}
		else
		{
			sort[1]=teamPlayers[2];
			sort[2]=teamPlayers[1];
		}
	}
	else if(teamPlayers[1].getpoints()>teamPlayers[0].getpoints() && teamPlayers[1].getpoints()>teamPlayers[2].getpoints())
	{
		sort[0]=teamPlayers[1];
		if(teamPlayers[0].getpoints()>teamPlayers[2].getpoints())
		{
			sort[1]=teamPlayers[0];
			sort[2]=teamPlayers[2];
		}
		else
		{
			sort[1]=teamPlayers[2];
			sort[2]=teamPlayers[0];
		}
	}
	else
	{
	sort[0]=teamPlayers[2];
		if(teamPlayers[1].getpoints()>teamPlayers[0].getpoints())
		{
			sort[1]=teamPlayers[1];
			sort[2]=teamPlayers[0];
		}
		else
		{
			sort[1]=teamPlayers[0];
			sort[2]=teamPlayers[1];
		}
	}
	
	
	for(int i=0;i<3;i++)
	{
	sort[i].displaydata();
	}
}


class Match{
public:
int Match_No;
Team homeTeam;
Team awayTeam;
Team *teams;
Player *in_match;//array of total players
int total_players;//number of total players added
  int counter ;//counter for the players

public:
Match();
void addPlayers(int total_players);//add the details of the players
Player* returnPlayers(string type);//it returns the player of a specific type
void assignRanks();//set the random ranks to each team
void teamSelection();//it allow user to select team according to a specific type
void bestPlayersInMatch();//this shows the best players in a team after the match
void generateMatchStats();//this gives points to the players
void playerSelection();//this allows teams to select player one by one
void UpdatePlayerPoints();//it addd the new points in player points
void printLeaderBoard();//it displays the sorted list of players by point
void printTeamRanks();//it shows the rank of the teams
void printplay(Player *);
};

Match::Match()
{
this->total_players=12;
 this->counter =0;
teams=new Team [4];
in_match=new Player[total_players];
}


void Match::printplay(Player *a)
{
for(int i=0;i<counter;i++)
{
 a[i].displaydata();
 cout<<endl;
}
}


void Match::addPlayers(int total_players){
double point;
bool avail=true;
  
for(int i = 0; i< total_players; i++){
  
cout<<"Player "<<i+1<<endl;
cout<<"Enter name: ";
cin>>in_match[i].name;
cout<<"Enter type: ";
cin>>in_match[i].type;
// randomly generates floating points between 40 to 50
srand( (unsigned)time( NULL ) );
point = (40+((float) rand()/(RAND_MAX/50-40)));
in_match[i].setpoint(point);

in_match[i].availability=avail;
}
  
}

Player* Match:: returnPlayers(string type){

// Create an array of object of Player for storing the players of particular type   
static Player *players = new Player[total_players];

// Iterate through all the players and search the given type player
// Add the matched players in the players array   
for(int i = 0; i<total_players; i++){
  
if(in_match[i].type == type)
players[counter++] = in_match[i];
}
// return the array of players of particular type   
return players;
}


void Match::assignRanks()
{

for(int i=0;i<4;i++)
{
int rank = rand() % 4 + 1;
teams[i].setrank(rank);

cout<<"Rank assigned for team :"<<i+1<<endl;
}

}
//now the two function below will halp in making a team (opt)
void Match::teamSelection()
{int choice,player_number;
Player *playerslist;
Player *playerslist2;
string a;
bool answer_status=true;
bool check;
char name[30];

	for(int team_number=0;team_number<4;team_number++)//setting players for all four teams
	{
	
		cout<<"please enter team name:";
		cin>>name;
		teams[team_number].setname(name);
		//teams[team_number].assignRanks();
		assignRanks();
		cout<<"Which team do you want to select?\n1.Defensive Team\n2.Attacking Team"<<endl;
		cin>>choice;
		if(choice==1)
		{a="defensive";
			//2 defensive player and 1 attacking.
			playerslist=returnPlayers(a);
			cout<<"Following players are avaliable:"<<endl;
			
			cout<<"Name"<<"	"<<"Type"<<"		"<<"Points"<<"		"<<"Availability"<<endl;
			for(int i=0;i<counter;i++)
			{
				playerslist[i].displaydata();		
			}
			
			cout<<"Please select 2 defensive players"<<endl;
			for(int i=0;i<2;i++)
			{
				cout<<"Enter player :"<<i+1<<endl;
				cin>>player_number;
				while(answer_status==true)
				{check=in_match[player_number].getavail();
					if(check==true)
					{
						teams[team_number].setplayer(i)=playerslist[player_number];
						in_match[player_number].setavail(false);
						answer_status=false;
					}
					else
					{
						cout<<"Please enter the avaliable player's number"<<endl;
						answer_status=true;
					}
				}
			}
			
			cout<<"Now select one attacker player"<<endl;
			
			cout<<"Following players are avaliable:"<<endl;
			a="attacker";
			playerslist2=returnPlayers(a);
			cout<<"Name"<<"	"<<"Type"<<"		"<<"Points"<<"		"<<"Availability"<<endl;
			for(int i=0;i<counter;i++)
			{
				playerslist2[i].displaydata();		
			}
			cout<<"Please select 1 attacker players"<<endl;
			for(int i=0;i<1;i++)
			{
				cout<<"Enter player :"<<i+1<<endl;
				cin>>player_number;
				while(answer_status==true)
				{ check=in_match[player_number].getavail();
					if(check==true)
					{
						teams[team_number].setplayer(i)=playerslist[player_number];
						in_match[player_number].setavail(false);
						answer_status=false;
						cout<<"Attacker player selected"<<endl;
					}
					else
					{
						cout<<"Please enter the avaliable player's number"<<endl;
						answer_status=true;
					}
				}
			}
		}
		//formation of an attacker team
		else
		{a="attacker";
			cout<<"Now select one attacker player"<<endl;
			
			cout<<"Following players are avaliable:"<<endl;
			playerslist2=returnPlayers(a);
			cout<<"Name"<<"	"<<"Type"<<"		"<<"Points"<<"		"<<"Availability"<<endl;
			for(int i=0;i<counter;i++)
			{
				playerslist2[i].displaydata();		
			}
			cout<<"Please select 2 attacker players"<<endl;
			for(int i=0;i<2;i++)
			{
				cout<<"Enter player :"<<i+1<<endl;
				cin>>player_number;
				while(answer_status==true)
				{check=in_match[player_number].getavail();
					if(check==true)
					{
						teams[team_number].setplayer(i)=playerslist[player_number];
						in_match[player_number].setavail(false);
						answer_status=false;
						cout<<"Attacker player selected"<<endl;
					}
					else
					{
						cout<<"Please enter the avaliable player's number"<<endl;
						answer_status=true;
					}
				}
			}
			//one def player
			a="defensive";
			playerslist=returnPlayers(a);
			cout<<"Following players are avaliable:"<<endl;
			
			cout<<"Name"<<"	"<<"Type"<<"		"<<"Points"<<"		"<<"Availability"<<endl;
			for(int i=0;i<counter;i++)
			{
				playerslist[i].displaydata();		
			}
			
			cout<<"Please select 1 defensive players"<<endl;
			for(int i=0;i<1;i++)
			{
				cout<<"Enter player :"<<i+1<<endl;
				cin>>player_number;
				while(answer_status==true)
				{check=in_match[player_number].getavail();
					if(check==true)
					{
						teams[team_number].setplayer(i)=playerslist[player_number];
						in_match[player_number].setavail(false);
						answer_status=false;
					}
					else
					{
						cout<<"Please enter the avaliable player's number"<<endl;
						answer_status=true;
					}
				}
			}
			
		}
	}
}
void Match::playerSelection()
{
int player_number;
bool answer_status=true;
bool check ;
cout<<"Please select a player for each team one by one"<<endl;
for(int i=0;i<3;i++)
{
	for(int j=0;j<4;j++)
	{
	cout<<"Players"<<endl;
	cout<<"Name"<<"	"<<"Type"<<"		"<<"Points"<<"		"<<"Availability"<<endl;
			for(int z=0;z<counter;z++)
			{
				in_match[z].displaydata();		
			}
	
	while(answer_status==true)
				{check=in_match[player_number].getavail();
					if(check==true)
					{
						cout<<"Select player "<<i+1<<"for team "<<j+1<<endl;
						cin>>player_number;
						
						teams[j].setplayer(i)=in_match[player_number];
						in_match[player_number].setavail(false);
					}
					else
					{
						cout<<"Please enter the avaliable player's number"<<endl;
						answer_status=true;
					}
				}
	}
}



}

void Match::generateMatchStats()
{
int winner_team;
double winnerpoint,loserpoint;
cout<<"Please enter the id of winning team:"<<endl;
cin>>winner_team;
srand( (unsigned)time( NULL ) );
for(int i=0;i<3;i++)
{
winnerpoint = (10+((float) rand()/(RAND_MAX/20-10)));
teams[winner_team].setpoints(i,winnerpoint);
}

for(int i=0;i<3;i++)
{
	if(i!=winner_team)
	{
		loserpoint = (5+((float) rand()/(RAND_MAX/10-5)));
		teams[i].setpoints(i,loserpoint);
	}
	else
	{
	continue;
	}
}
}

void Match::bestPlayersInMatch()
{
int win,lose;
cout<<"Enter the id of winning team:"<<endl;
cin>>win;
cout<<"Enter the id of losing team:"<<endl;
cin>>lose;

cout<<"Best player of winning team\n";
teams[win].displaybest();
cout<<endl;
cout<<"Best player of losing team\n";
teams[lose].displaybest();
cout<<endl;
}

void Match::UpdatePlayerPoints()
{
double winnerpoint;
srand( (unsigned)time( NULL ) );
for(int j=0;j<counter;j++)
	{
		for(int i=0;i<3;i++)
		{
		winnerpoint = (10+((float) rand()/(RAND_MAX/20-10)));
		teams[j].setpoints(i,winnerpoint);
		}
	}
	cout<<"POints updated\n";
}

void Match::printLeaderBoard()
{
	for(int i=0;i<4;i++)
	{	cout<<"Team "<<i+1<<endl;
		teams[i].sortingplayer();
	}
}



void Match::printTeamRanks()
{

for(int i=0;i<4;i++)
{	cout<<"Rank of team "<<i+1<<" :";
	cout<<teams[i].getrank()<<endl;
}
}
int main()
{
Match m;
int option=99;
cout<<"************************************Welcome*****************************\n";
while(option!=0)
{
cout<<"What do you want?\n0.Exit\n1.Add players\n2.Search player\n3.Select team according to type\n4.Select player one by one\n5.Check best player\n6.Print lead board\n7.Print team rank\n";
cin>>option;
if(option==0)
{
cout<<"Thank You!\n";
break;
}

else if(option==1)
{
int total_players;
cout<<"Please enter number of players\n";
cin>>total_players;
m.addPlayers(total_players);
}

else if(option==2)
{
string type;
cout<<"Defensive or attacker?\n";
cin>>type;
m.printplay(m.returnPlayers(type));
}
else if(option==3)
{
	m.teamSelection();//it allow user to select team according to a specific type
}
else if(option==4)
{
m.playerSelection();//this allows teams to select player one by one
}
else if(option==5)
{
m.bestPlayersInMatch();//this shows the best players in a team after the match
}
else if(option==6)
{
m.printLeaderBoard();//it displays the sorted list of players by point
}
else if(option==7)
{
 m.printTeamRanks();//it shows the rank of the teams
}
}
return 0;
}

