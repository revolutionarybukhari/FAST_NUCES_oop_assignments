#include<iostream>
using namespace std;

class Array{
int size ;
int *array;
public:
Array();// a default constructor
Array(int size);// a parametrized constructor initializing an Array of predefined
Array(int *arr, int size);// initializes the Array with an existing Array
Array(const Array &);// copy constructor
int operator[](int i);// returns the integer at index [i] after checking the out of
void operator=(const Array);//copy the array
Array operator+(const Array);//adds two Array
Array operator-(const Array);//subtracts two Array
void operator++();//adds one to each element of Array
Array& operator--(int);//subtracts one from each element of array
bool operator==(const Array);//returns true if two arrays are same
bool operator!();// returns true if the Array is empty
void operator+=(const Array&);//adds two Array
void operator-=(const Array&);//subtracts two Array
int operator()(int idx, int val);// erases the value val at idx. Returns 1 for a
//successful deletion and -1 if idx does not exists or is invalid. Shift the
//elements after idx to the left.
void setarray();
void getarray();
int getsize();
int* getarr();
~Array();// destructor...
};
istream& operator<<(istream& input, Array&);//Inputs the Array
ostream& operator>>(ostream& ouput,Array&); //Outputs the Array

int Array::getsize()
{
return this->size;
}
int* Array::getarr()
{
return this->array;
}

void Array::getarray()
{
	cout<<"\nSize of array:\n";
	cout<<this->size<<endl;
	cout<<"Array:\n";
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}


void Array::setarray()
{
	cout<<"\nPlease enter the size of array:\n";
	cin>>this->size;
	for(int i=0;i<size;i++)
	{
		cout<<"Enter value of index "<<i+1<<endl;
		cin>>array[i];
	}
}


Array::Array()
{
	size=10;
	array=new int [size];

}

Array::Array(int size)// a parametrized constructor initializing an Array of predefined
{
this->size=size;

//delete []array;
this->array=new int [size];
}

Array::Array(const Array &a)// copy constructor
{
	this->size=a.size;
	this->array=new int [this->size];
	for(int i=0;i<this->size;i++)
	{
		this->array[i]=a.array[i];
	}

	cout<<"\n COPY MADE \n";
}

Array::Array(int *arr, int size)// initializes the Array with an existing Array
{
	this->size=size;
	this->array=new int [this->size];
	for(int i=0;i<this->size;i++)
	{
		this->array[i]=arr[i];
	}
}

int Array::operator[](int i)
{
int val,ii;
	if(i>=0 && i>this->size)
	{
		cout<<"\nInvalid index\n";
		cout<<"PLease renter the index:\n";
		cin>>ii;
		this->operator[](ii);
	}
	else
	{
		val= array[i];
		return val;
	}
return 0;
}


void Array::operator=(const Array arr)//copy the array
{
	this->size=arr.size;
	//delete [] this->array;
	if(this->array!=NULL)
	{
		delete [] this->array;
	}
	this->array=new int [this->size];
	for(int i=0;i<this->size;i++)
	{
		this->array[i]=arr.array[i];
	}
}


Array Array::operator+(const Array arr)//adds two Array
{
int s;
int s2,check;
Array temp2(this->size);

if(this->size>arr.size)
{
	s=this->size;
	s2=arr.size;
	check=1;
}
else
{
	s=arr.size;
	s2=this->size;
	check=0;
}
Array temp(s);
	for(int i=0;i<s;i++)
	{
		if(i<=s2)
		{
			temp.array[i]=this->array[i]+arr.array[i];
		}
		else
		{
			if(check==1)
			{
				temp.array[i]=this->array[i];
			}
			else
			{
				temp.array[i]=arr.array[i];
			}
		}
	}

return temp;


}

Array Array::operator-(const Array arr)
{
int s;
int s2,check;
if(this->size>arr.size)
{
	s=this->size;
	s2=arr.size;
	check=1;
}
else
{
	s=arr.size;
	s2=this->size;
	check=0;
}
Array temp(s);
	for(int i=0;i<s;i++)
	{
		if(i<=s2)
		{
			temp.array[i]=this->array[i]-arr.array[i];
		}
		else
		{
			if(check==1)
			{
				temp.array[i]=this->array[i];
			}
			else
			{
				temp.array[i]=arr.array[i];
			}
		}
	}

return temp;
}

void Array::operator++()//adds one to each element of Array
{
	for(int i=0;i<this->size;i++)
	{
		this->array[i]+=1;
	}

}

Array& Array::operator--(int p)//subtracts one from each element of array
{
Array temp0(this->size);
temp0=*this;
	for(int i=0;i<this->size;i++)
	{
		this->array[i]-=1;
	}
return *this;
}

bool Array::operator==(const Array arr)//returns true if two arrays are same
{
bool flag;
	for(int i=0;i<this->size;i++)
	{
		if(this->array[i]==arr.array[i])
		{
			flag=true;
		}
		else
		{
			flag=false;
		}
	}
return flag;
}

bool Array::operator!()// returns true if the Array is empty
{
bool flag;
int count=0;
int s= *(&array + 1) - array;
	for(int i=0;this->array[i]!=NULL;i++)
	{
		count++;
	}
	if(count==0 ||  s==0)
		{
			flag=true;
		}
		else
		{
			flag=false;
		}
return flag;

}

void Array::operator+=(const Array& arr)//adds two Array
{
int s;
int s2,check;
if(this->size>arr.size)
{
	s=this->size;
	s2=arr.size;
	check=1;
}
else
{
	s=arr.size;
	s2=this->size;
	check=0;
}
Array temp(s);
	for(int i=0;i<s;i++)
	{
		if(i<=s2)
		{
			temp.array[i]=this->array[i]+arr.array[i];
		}
		else
		{
			if(check==1)
			{
				temp.array[i]=this->array[i];
			}
			else
			{
				temp.array[i]=arr.array[i];
			}
		}
	}

this->size=temp.size;
delete []array;
for(int i=0;i<size;i++)
{
this->array[i]=temp.array[i];
}

}

void Array::operator-=(const Array& arr)//subtracts two Array
{
int s;
int s2,check;
if(this->size>arr.size)
{
	s=this->size;
	s2=arr.size;
	check=1;
}
else
{
	s=arr.size;
	s2=this->size;
	check=0;
}
Array temp(s);
	for(int i=0;i<s;i++)
	{
		if(i<=s2)
		{
			temp.array[i]=this->array[i]-arr.array[i];
		}
		else
		{
			if(check==1)
			{
				temp.array[i]=this->array[i];
			}
			else
			{
				temp.array[i]=arr.array[i];
			}
		}
	}

this->size=temp.size;
delete []array;
for(int i=0;i<size;i++)
{
this->array[i]=temp.array[i];
}
}

int Array::operator()(int idx, int val)// erases the value val at idx. Returns 1 for a
{int num;
Array temp(this->size-1);
	if(idx<0 || idx>=size)
	{
		cout<<"INvalid index!!\nPlease re-enter the index:\n ";
		//cin>>num;
		//this->operator()(num,val);
		return -1;
	}
	else
	{
		if(array[idx]==val)
		{
			int pos=0;
			for(int i=0;i<size;i++)
			{
				if(i==idx)
				{
					continue;
				}
				else
				{
					temp.array[pos]=array[i];
					pos++;
				}
			}

		this->size=temp.size;
		//array=new int [this->size];
		delete []array;
		for(int i=0;i<size;i++)
		{
		this->array[i]=temp.array[i];
		}		return 1;
		}
		else
		{
			cout<<"Match not found!\n";
			return -1;
		}
	}
return 0;
}


Array::~Array()// destructor...
{
cout<<"\nDestructor Called\n";
//delete []array;
}
istream& operator<<(istream& input,Array &arr)//Inputs the Array
{
	arr.setarray();
	return input;
}
ostream& operator>>(ostream& ouput,Array &arr)
{
	arr.getarray();
	return ouput;
}


int main()
{
int index;
Array a1;
a1.setarray();
cout<<"\n USING COPY CONSTRUCTOR TO MAKE A COPY OF ABOVE ARRAY\n";
Array a2(a1.getarr(),a1.getsize());

cout<<"\nEnter the index to find the element of array\n";
cin>>index;
cout<<a1[index-1];
cout<<endl;

cout<<"USING = OPERATOR TO MAKE A NEW ARRAY EQUAL TO 1ST\n";
Array a3;
a3.operator=(a1);
a3.getarray();



cout<<"Let's Check that is the function working properly!!\n";
if(a3==a1)
{
cout<<"THey are equal!\n";
}
else{
cout<<"They are not equal!\n";
}

cout<<"LET'S ADD A1 AND A2\n";
Array a4(a1.getsize());
a4=a1+a2;
a4.getarray();
cout<<"LET'S SUBTRACT A1 FROM ABOVE ARRAY\n";
Array a5(a1.getsize());
a5=a4-a1;
a5.getarray();
cout<<"LET'S use A1++\n";
++a1;
a1.getarray();
cout<<"LET'S use A1--\n";
Array a6=a1--;
a6.getarray();
bool flag;
cout<<"LET'S use !() operator for A1\n";
flag=a1.operator!();
if(flag)
{
cout<<"ARRAY EMPTY!\n";
}
else{
cout<<"ARRAY NOT EMPTY!\n";
}


cout<<"LET'S use += operator for A1 and A2\n";

a1+=a2;
a1.getarray();

cout<<"LET'S use -= operator for A1 and A2\n";
a1-=a2;
a1.getarray();
int value;
cout<<"Enter index and value to find and delete for a1\n";
cin>>index>>value;
a1(index-1,value);
a1.getarray();

cout<<"\nNOW TESTING ISTREAM AND OSTREAM FUNCTIONS \n";
 Array t1;
cout<<"Using istream cin<<t1\n";
cin<<t1;
cout<<"\nUsing ostream cout>>t1\n";
cout>>t1;
return 0;
}









