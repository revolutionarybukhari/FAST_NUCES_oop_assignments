#include<iostream>
#include<cstring>
using namespace std;


class String{
 // think about the private data members...
char * string;
int size;

 public:
 // provide definitions of following functions...
 String();// default constructor
 String(char *str);// initializes the string with constant cstring
 String(const String &);// copy constructor to initialize the string fromexisting,→ string
 String(int x);// initializes a string of pre-defined size
 char operator[](int i);// returns the character at index [x]
 String& operator+(String str );// append a String at the end of string
 String& operator-(String substr);//removes the substr from the string
 bool operator!();// returns true if string is empty..
 String& operator=(const String&);// Copy one string to another ...
 bool operator==(const String&);//returns true if two strings are equal
 int operator()(char);// returns the index of character being searched.
 String operator*(int a);//multiples the string by i times and return the string.,→ Remember the Python functionality for *
 int length();// returns the length of string
~String();// destructor...
  void setsize(int );
  void setstring( );
  int getsize();
  void getstring();

 };


 istream& operator>>(istream& input, String &);//Inputs the string
 ostream& operator<<(ostream& ouput, String); //Outputs the string

String::String()
{
	size=0;
	string=new char[size];
	string[size]='\0';
}
String::String(char *str)
{
int counter=0;
	while(str[counter]!='\0')
	{
		counter++;
	}
	size=counter;
	string=new char [size];
	for(int i=0;i<size;i++)
	{
		string[i]=str[i];
	}
}

String:: String(const String &str)// copy constructor to initialize the string fromexisting,→ string
{
	this->size=str.size;
	this->string=new char[size];
	for(int i=0;i<size;i++)
	{
		this->string[i]=str.string[i];
	}

}

String::String(int x)// initializes a string of pre-defined size
{
if(x<0)
{
cout<<"Invalid length\n";
}
else
{
this->size=x;
string=new char [size];
//string[size]='\0';

}
}

char String::operator[](int i)// returns the character at index [x]
 {
 if(i<0 || i>size)
 {
 	cout<<"Invalid index !\n";
 	return '\0';
 }
 else
 {
 	return string[i];
 }

 }
 String& String::operator+(String str )// append a String at the end of string
{
int sizee;
char *temp_array;
sizee=this->size+str.size;
temp_array=new char [sizee];
int c=0;
for(int i=0;i<sizee;i++)
{
	if(i<this->size)
	{
		temp_array[i]=this->string[i];
	}
	else
	{
		temp_array[i]=str.string[c];
		c++;
	}
}

delete []string;
this->size=sizee;
//this->string=new char [this->size];
this->string=temp_array;
return *this;
}

 String& String::operator-(String substr)//removes the substr from the string
 {
 int size_of_substring;//=strlen(substr);
 int counter1=0;
	while(substr[counter1]!='\0')
	{
		counter1++;
	}
 size_of_substring=counter1;
int counter2=0;
while(string[counter2]!='\0')
	{
		counter2++;
	}
this->size=counter2;
 //checking for the substring
 int counter=0,repeat=0;
	bool check=false;
	for(int i=0 ; i<this->size;i++)
	{int check2=0;
	//bool check=false;
		for(int j=0;substr.string[j]!='\0';j++)
		{
		  if(substr.string[j]==string[i+j] )
		  {

		    check=true;
		    check2++;

		  }
		  else if(string[i+j]!=substr.string[j])
		  {
		  	check=false;
		    counter++;
		  }
		}
		if(check2==counter1)
		{
			if(check==true)
			{

			 //repeat++;
				counter=i;
			 break;
			}
		}
	}

		if(check==true)
		{
			//counter=counter+2;
			//return counter;
			for(int l=0;l<substr.size;l++)
			{
				this->string[counter+l]='#';
			}


	int c=0;

	int sizee=this->size;
	char *str=new char[sizee];
	for(int i=0;i<this->size;i++)
	{	if(string[i]=='#')
		{
			continue;
		}
		else
		{
			str[c]=string[i];
						c++;
		}
	}
	int pos=sizee-1;
	for(int i=counter1;i>0;i--)
	{
		str[pos]='\0';
		pos--;

	}
	this->string=str;
		}
		else
		{
			cout<<"String Not found!\n";
			return *this;
		}
return *this;
 }


  bool String::operator!()// returns true if string is empty..
  {
  	if(strlen(string)==0 || size==0)
  	{
  		return true;
  	}
  	else
  	{
  		return false;
  	}
 }

String& String::operator=(const String& str)// Copy one string to another ...
 {

	 this->size=str.size;
	 this->string=new char[size];
	 for(int i=0;i<size;i++)
	 {
	 	string[i]=str.string[i];
	 }
	return *this;
 }

bool String::operator==(const String& str)//returns true if two strings are equal
{bool check=true , decision=false;
if(this->size==str.size)
{
	for(int i=0;i<size;i++)
	{
		if(string[i]==str.string[i])
		{
			if(check==true)
			{
				decision=true;
				continue;
			}
		}
		else
		{
			check=false;
			decision=false;
			break;
		}

	}
}
else
{
decision;
}
return decision;
}

int String::operator()(char alpha)// returns the index of character being searched.
{
int index;
bool check=true;
	for(int i=0;i<size;i++)
	{
		if(string[i]==alpha)
		{
			index=i;
			check=true;
			break;
		}
		else
		{
			check=false;
			continue;
		}
	}
	if(check==false)
	{
		cout<<"No match found ! \n";
		//exit(0);
	}
	else
	{
		return index;
	}
	return 0;
}

String String::operator*(int a)//multiples the string by i times and return the string.,→ Remember the Python functionality for *
{
int c=0;
int counter1=0;
	while(this->string[counter1]!='\0')
	{
		counter1++;
	}
	this->size=counter1;
	int temp_size=this->size*a;
	char *temp_string=new char [temp_size];

	for(int i=0;i<a;i++)
	{
		for(int j=0;j<this->size;j++)
		{
			temp_string[c]=this->string[j];
			c++;
		}
	}

delete []string;
this->size=temp_size;
this->string=temp_string;
return *this;
}

 int String::length()// returns the length of string
{

	int counter=0;
	while(this->string[counter]!='\0')
	{
		counter++;
	}
	if(counter==0)
	{
		return this->size;
	}
return counter;
}

 String::~String()// destructor...
  {

  }


  void String::setsize(int s )
  {
  	this->size=s;
  }
  void String::setstring( )
  {
  //if(this->string!=NULL)
  //{
  //delete [] string;
  //}
  	  	int si;
    	if(size==0)
    	{
    	cout<<"PLease enter size:\n";
     	cin>>si;
    	this->size=si;
    	string=new  char [si];
    	}
    	else
    	{
  		string=new  char [this->size];
    	}
  cout<<"Enter string:";
  //cin.ignore();
  cin.getline(string,size);
  //cin>>s;


//  	for(int i=0;i<this->size;i++)
  //	{
  	//	this->string[i]=str[i];
  	//}
  }
  int String::getsize()
  {
  	return this->size;
  }
  void String::getstring()
  {

	     	cout<<string;
  }


istream& operator>>(istream& input, String &str)//Inputs the string
  {
	   str.setstring();
	   return input;
  }

ostream& operator<<(ostream& ouput,String str) //Outputs the string
   {
   	str.getstring();
   	return ouput;
   }

   int main()
   {/*
  char* tmp;
  cout<<"DEFAULT CONSTRUCTOR CREATED SUCCESSFULLY"<<endl;
  String s0;
  cout<<"Please enter a string to initilize the obj with constant string:"<<endl;
  char arr[100];
  cin.getline(arr,100);
  String s1(arr);
  cout<<"Initilization completed!\n";

  cout<<"*****NOW USING COPY CONSTRUCTOR******"<<endl;
  String s2(s1);
  cout<<"Copy constructor work completed!!!!\n";

  cout<<"Enter the length of the string to initilize it with that SIZE:"<<endl;
  int s;
  cin>>s;
  String s3(s);
  cout<<"String of size "<<s<<" sucessfully made!!!\n";

  cout<<"Enter index number I will show you the character!!! ;)"<<endl;
  cin>>s;
  char chr;
  chr=s2[s-1];
  cout<<chr<<endl;
    char arr1[100];
  cout<<"ARE YOU HAPPY!!! Well I AM\n";
  cout<<"OK NOW LET'S APPEND THE STRING.ARE YOU EXCITED? WELL I AM!\n";
  cout<<"Please enter a string to merge with the pervious string u entered:"<<endl;
cin.ignore();
  cin.getline(arr1,100);
  String s4(arr1);
  String merged=s2.operator+(s4);
  int temp_size=merged.getsize();
  //char *array;
  //array=merged.getstring();
  //	for(int i=0;i<temp_size;i++)
  //	{
  //		cout<<array[i];
  //	}
      cout>>merged;
      cout<<endl;
  cout<<"NOW LET'S REMOVE A SUBSTRING:\n";
  cout<<"Please enter a string to remove from the merged one:"<<endl;
  char arr2[100];
  cin.getline(arr2,100);
  String s5(arr2);
  String del;
  del=merged.operator-(s5);
      cout>>del;
      cout<<endl;
  cout<<"\n";
  cout<<"I have created an empty string and lets check our fuction working!\n ";
  bool flag;
  flag=s0.operator!();
  cout<<flag<<endl;

  cout<<"That was nice! Well now I will use this function = to check its working!\n";
  bool flag2;
  String s6= s0.operator=(merged);
  flag2= s6.operator==(merged);
  cout<<flag2<<endl;
  int index;
  char char2;
    cout<<"\n";
  cout<<"Enter a character and let's find it's index in merged string XD:"<<endl;
  cin>>char2;

   cout<<"index is "<<merged(char2)<<endl;
 cout<<"LET'S PLAY ENTER THE NUMBER OF TIMES YOU WANNA REPEAT STRING  "<<endl;
String s8;
 int num;
 cin>>num;

 String s7=  del.operator *(num);
cout<<endl;
cout>>s7;
cout<<"Using input overloaded operator \n";
cin<<s8;
cout<<"Using output overloaded operator \n";
cout>>s7;
//ouput<<s7;
*/

String s1(10);
cout << "Input 'HelloTest' :";
cin>>s1;
cout<<s1;
    String s2("HelloTest");
    cout<<s1;
   // ASSERT_EQ(true,s2==s1 );
if(s2==s1)
{
cout<<"True";
}
else
{
cout<<"False";
}
return 0;
   }



