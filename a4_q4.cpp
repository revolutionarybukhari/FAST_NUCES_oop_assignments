#include<iostream>
#include<string>
using namespace std;

class Polynomial{
// think about the private data members...
// the matrix should store real numbers
int *coeff;
int degree;

public:
//include all the necessary checks before performing the operations in the functions
Polynomial();// a default constructor
Polynomial(int);// a parametrized constructor
Polynomial(const Polynomial &);// copy constructor
Polynomial& operator=(const Polynomial &);//assigns (copies) a Polynomial. Returns,→ the same
bool operator==(const Polynomial &);//Compare and return true if equal
Polynomial operator+(const Polynomial &);//adds two Polynomial and returns the result
Polynomial operator-(const Polynomial &);//subtracts two Polynomial and returns the,→ result
Polynomial operator*(const Polynomial &);//multiplies two Polynomial and returns the,→ result
void operator+=(const Polynomial&);//adds two polynomials
void operator-=(const Polynomial&);//subtracts two Matrices
~Polynomial();
operator string();
void seteq();
void geteq();

};
istream& operator<<(istream& input, Polynomial&);//Inputs the Array
ostream& operator>>(ostream& ouput, Polynomial); //Outputs the Array

Polynomial::operator string(){
        string s="";
        string temp;

        	//cout<<"eq = ";
	for(int i=this->degree;i>=0;i--)
	{	if(i!=0)
		{	if(coeff[i]!=1 && coeff[i]!=0)
			{
				//cout<<coeff[i]<<"x^"<<i;
				//temp=to_string(coeff[i])+"x^";
				if(i!=1)
				{
					temp=to_string(coeff[i])+"x^"+to_string(i);
				}
				else
				{
					temp=to_string(coeff[i])+"x";
				}
            			s=s+temp;
				if(i!=0 || i-1!=0)
				{
					if(i-1!=0 && coeff[i-1]!=0)
					{
						if(coeff[i-1]<0 )
						{
							temp=" + ";
			    				s=s+temp;
						}
						else
						{
							temp=" + ";
			    				s=s+temp;

						}
					}
				}
			}

			else if(coeff[i]==1 && coeff[i]!=0)
			{


				if(i!=1)
				{
					temp="x^"+to_string(i);
				}
				 else
				{
					temp="x";
				}
            			s=s+temp;
				if(i!=0 )
				{	if(i-1!=0 && coeff[i-1]!=0)
					{
						if(coeff[i+1]<0 )
						{
							temp=" - ";
			    				s=s+temp;
						}

						else if(coeff[i+1]>0 )
						{
							temp=" + ";
			    				s=s+temp;

						}
					}

				}

			}

			else
			{
				continue;
			}
		}
		else
		{
			if(coeff[i]!=0)
			{
				temp=to_string(coeff[i]);
            			s=s+temp;
            		}
            		else
            		{
            		continue;
            		}
		}
	}



        return s;
    }

void Polynomial::seteq()
{
	for(int i=this->degree;i>=0;i--)
	{
		cout<<"Enter val for x^ "<<i<<endl;
		cin>>coeff[i];
	}

}
void Polynomial::geteq()
{
	int s=this->degree;
	cout<<"eq = ";
	for(int i=this->degree;i>=0;i--)
	{	if(i!=0)
		{	if(coeff[i]!=1 && coeff[i]!=0)
			{
				//cout<<coeff[i]<<"x^"<<i;
				//temp=to_string(coeff[i])+"x^";
				if(i!=1)
				{
					cout<<coeff[i]<<"x^"<<i;
				}
				else
				{
					cout<<coeff[i]<<"x";
				}
            			//s=s+temp;
				if(i!=0 || i-1!=0)
				{
					if((i-1)!=0 )
					{
						if(coeff[i-1]<0 )
						{
							cout<<" + ";
			    				//s=s+temp;
						}
						else
						{
							cout<<" + ";
			    				//s=s+temp;

						}
					}
				}
			}

			else if(coeff[i]==1 && coeff[i]!=0)
			{


				if(i!=1)
				{
					cout<<"x^"<<i;
				}
				 else
				{
					cout<<"x";
				}
            			//s=s+temp;
				if(i!=0 )
				{	if(i-1!=0 && coeff[i-1]!=0)
					{
						if(coeff[i+1]<0 )
						{
							cout<<" - ";
			    				//s=s+temp;
						}

						else if(coeff[i+1]>0 )
						{
							cout<<" + ";
			    				//s=s+temp;

						}
					}

				}

			}

			else
			{
				continue;
			}
		}
		else
		{
			if(coeff[i]!=0)
			{
				cout<<coeff[i];

            		}
            		else
            		{
            		continue;
            		}
		}
	}


}


Polynomial::Polynomial()// a default constructor
{
	this->degree=0;
	coeff=new int[degree+1];
	for(int i=0;i<degree+1;i++)
	{
		coeff[i]=0;
	}
}

Polynomial::Polynomial(int num)// a default constructor
{
	this->degree=num;
	coeff=new int[degree+1];
	for(int i=0;i<degree+1;i++)
	{
		coeff[i]=0;
	}
}
Polynomial::Polynomial(const Polynomial & temp)// copy constructor
{
	this->degree=temp.degree;
	//if(this->coeff!=NULL)
	//{
	//	delete [] coeff;
	//}
	coeff=new int[degree+1];
	for(int i=0;i<degree+1;i++)
	{
		coeff[i]=temp.coeff[i];
	}
}

Polynomial& Polynomial::operator=(const Polynomial & temp)//assigns (copies) a Polynomial. Returns,→ the same
{
	int size;
	for(int i=0;temp.coeff[i]!=NULL;i++)
	{
		size=i+1;

	}
	this->degree=size-1;
	if(this->coeff!=NULL)
	{
		delete [] coeff;
	}
	coeff=new int[size];
	for(int i=0;i<size;i++)
	{
		coeff[i]=temp.coeff[i];
	}
	return *this;
}

bool Polynomial::operator==(const Polynomial & temp)//Compare and return true if equal
{
	bool flag;
	for(int i=0;i<degree+1;i++)
	{

			if(coeff[i]==temp.coeff[i])
			{
				flag=true;
			}
			else
			{
				flag=false;
				break;
			}
	}
	return flag;
}

Polynomial Polynomial:: operator+(const Polynomial & temp)//adds two Polynomial and returns the result
{

int s;
int s2,check;
//Polynomial temp2(this->size);

if(this->degree>temp.degree)
{
	s=this->degree;
	s2=temp.degree;
	check=1;
}
else
{
	s=temp.degree;
	s2=this->degree;
	check=0;
}
Polynomial result(s);
	for(int i=0;i<s+1;i++)
	{
		if(i<s2+1)
		{
			result.coeff[i]=this->coeff[i]+temp.coeff[i];
		}
		else
		{
			if(check==1)
			{
				result.coeff[i]=this->coeff[i];
			}
			else
			{
				result.coeff[i]=temp.coeff[i];
			}
		}
	}

return result;


/*
Polynomial result(this->degree);
	for(int i=0;i<this->size;i++)
	{
		result.coeff[i]=this->coeff[i]+temp.coeff[i];
	}


return result;
*/

}



Polynomial Polynomial::operator-(const Polynomial & temp)
{
/*Polynomial result(this->degree);
//result.degree=this->degree;
	for(int i=0;i<this->size;i++)
	{
		result.coeff[i]=this->coeff[i]-temp.coeff[i];
	}
return result;
*/

int s;
int s2,check;
//Polynomial temp2(this->size);

if(this->degree>temp.degree)
{
	s=this->degree;
	s2=temp.degree;
	check=1;
}
else
{
	s=temp.degree;
	s2=this->degree;
	check=0;
}
Polynomial result(s+1);
	for(int i=0;i<s+1;i++)
	{
		if(i<=s2)
		{
			result.coeff[i]=this->coeff[i]-temp.coeff[i];
		}
		else
		{
			if(check==1)
			{
				result.coeff[i]=this->coeff[i];
			}
			else
			{
				result.coeff[i]=temp.coeff[i];
			}
		}
	}

return result;


}
/*Polynomial result(this->degree);
//result.degree=this->degree;
	for(int i=0;i<this->degree;i++)
	{
		result.coeff[i]=this->coeff[i]*temp.coeff[i];
	}
return result;*/
Polynomial Polynomial:: operator*(const Polynomial & b)
{
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c(this->degree+b.degree);

      for ( int i = 0; i <= a.degree; i++ )
      {
         for ( int j = 0; j <= b.degree; j++ )
         {
            c.coeff[i+j] += ( a.coeff[i] * b.coeff[j] );

	 }
      }
      return c;

}

void Polynomial::operator+=(const Polynomial& temp)//adds two polynomials
{
/*	for(int i=0;i<this->size;i++)
	{
		this->coeff[i]+=temp.coeff[i];
	}
*/
int s;
int s2,check;
//Polynomial temp2(this->size);

if(this->degree>temp.degree)
{
	s=this->degree;
	s2=temp.degree;
	check=1;
}
else
{
	s=temp.degree;
	s2=this->degree;
	check=0;
}
Polynomial result(s);
	for(int i=0;i<s+1;i++)
	{
		if(i<=s2)
		{
			result.coeff[i]=this->coeff[i]+temp.coeff[i];
		}
		else
		{
			if(check==1)
			{
				result.coeff[i]=this->coeff[i];
			}
			else
			{
				result.coeff[i]=temp.coeff[i];
			}
		}
	}

this->degree=result.degree;
if(this->coeff!=NULL)
{
	delete [] coeff;
}
coeff=new int [degree+1];
for(int i=0;i<this->degree+1;i++)
{
	coeff[i]=result.coeff[i];
}




}

void Polynomial::operator-=(const Polynomial& temp)//adds two polynomials
{
/*	for(int i=0;i<this->size;i++)
	{
		this->coeff[i]+=temp.coeff[i];
	}
*/
int s;
int s2,check;
//Polynomial temp2(this->size);

if(this->degree>temp.degree)
{
	s=this->degree;
	s2=temp.degree;
	check=1;
}
else
{
	s=temp.degree;
	s2=this->degree;
	check=0;
}
Polynomial result(s);
	for(int i=0;i<s+1;i++)
	{
		if(i<=s2)
		{
			result.coeff[i]=this->coeff[i]-temp.coeff[i];
		}
		else
		{
			if(check==1)
			{
				result.coeff[i]=this->coeff[i];
			}
			else
			{
				result.coeff[i]=temp.coeff[i];
			}
		}
	}

this->degree=result.degree;
if(this->coeff!=NULL)
{
	delete [] coeff;
}
coeff=new int [degree+1];
for(int i=0;i<this->degree+1;i++)
{
	coeff[i]=result.coeff[i];
}



}

Polynomial::~Polynomial()
{
//cout<<"\nDestructor called\n";
}

istream& operator>>(istream& input,Polynomial & p)//Inputs the Array
{
p.seteq();
return input;
}


ostream& operator<<(ostream& ouput,Polynomial p)//Outputs the Array
{
p.geteq();
return ouput;

}

int main()
{
/*
cout<<"Default Constructor\n";
Polynomial p1;
//cin<<p1;

int num;
cout<<"\n**Parametrized**\n";
cout<<"Enter the degree:";
cin>>num;
Polynomial p2(num);
cin<<p2;
cout<<endl;

cout<<"Now using parameterize constructor p3(p2)\n";
Polynomial p3(p2);
cout>>p3;

cout<<"\nCheck p3 is equal p2\n";
if(p3==p2)
{
cout<<"They are equal\n";
}
else
{
cout<<"They are not equal\n";
}
cout<<"\nADDING P3 AND P2\n";
Polynomial p4(p3+p2);
p4.geteq();
cout<<endl;

cout<<"\nSubtract above sum AND P2\n";
Polynomial p5(p4-p3);
p5.geteq();
cout<<endl;

cout<<"\nMultiplying P3 AND P2\n";

cout>>p3;
cout<<"*"<<endl;
cout>>p2;
cout<<endl;
Polynomial p6=p3*p2;
p6.geteq();
cout<<endl;

cout<<"\nUSING += P3 AND P2\n";
//Polynomial p7;
p3+=p2;
p3.geteq();
cout<<endl;

cout<<"\nUSING -= P3 AND P2\n";
//Polynomial p8;
p3-=p2;
cout>>p3;

cout<<endl<<"CHECKING THE STRING OPERATOR\n";
string a;
a=string(p3);
cout<<a;
*/

 Polynomial x(2);
	cin>>x;// input 4x^2 + 3x + 1
	string s1=(string)x;
	string s2="4x^2 + 3x + 1";
	//ASSERT_EQ(0, s1.compare(s2));
	cout<<x;
	Polynomial z(1);
	cin>>z;// input x + 1

	Polynomial y=x-z;
	cout<<y;
	cout<<endl;
	string s3=(string)y;
	string s4="4x^2 + 2x";
	//ASSERT_EQ(0, s3.compare(s4));
	cout<<string(s3);
	cout<<endl;
	cout<<string(s4);
/*
Polynomial x(3);
	cin>>x;// input 4x^3 + 3x + 2 which is first input will be 4, second will be 0, third will be 3, fourth will be 2
	string s1=(string)x;
	string s2="4x^3 + 3x + 2";
	//ASSERT_EQ(0, s1.compare(s2));
	cout<<s2;
	cout<<endl;
	cout<<x;
	Polynomial z(x);
	string s3=(string)z;
	cout<<endl;
	//ASSERT_EQ(0, s3.compare(s2));
	cout<<z;
*/
return 0;
}


