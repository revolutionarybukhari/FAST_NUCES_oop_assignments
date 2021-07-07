#include<iostream>
#include<iostream>
using namespace std;

class Matrix{
// think about the private data members...
// the matrix should store real numbers
int rows ;
int columns;
float **matrix;

public:
//include all the necessary checks before performing the operations in the functions
Matrix();// a default constructor
Matrix(int, int);// a parametrized constructor
Matrix(const Matrix &);// copy constructor
void operator()(int i, int j, float val);//set value at (i,j)
Matrix& operator=(const Matrix &);//assigns (copies) a Matrix. Returns the same
bool operator==(const Matrix &);//Compares two matrices
Matrix operator+(const Matrix &);//adds two Matrices and returns the result
Matrix operator-(const Matrix &);//subtracts two Matrices and returns the result
Matrix operator*(const Matrix &);//multiplies two Matrices elementwise and returns,→ the result
Matrix& operator++(int);//add one to every element
void operator+=(const Matrix&);//adds two Matrices
void operator-=(const Matrix&);//subtracts two Matrices
~Matrix();
void setvalue();
operator string();
void display(); 
};
istream& operator>>(istream& input,Matrix &);//Inputs the Array
ostream& operator<<(ostream& ouput,Matrix &); //Outputs the Array



Matrix::operator string(){
        string s="";
     	string temp;
     		   temp=to_string(this->rows)+"X"+to_string(this->columns)+"\n";
            			s=s+temp;
      int num;
        for(int i=0;i<rows;i++)
        {
        	
        	
        	
        	for(int j=0;j<columns;j++)
        	{
        		num=matrix[i][j];	 
        		 temp=to_string(num);
         	     	 s=s+temp;
         	     	 if((j+1)<columns)  
         	     	 {
         	     	 	temp="-";
         	     		s=s+temp;
         	     	 }
      		     	 
        	}
        	if((i+1)!=rows)
        	{
        		temp="\n*";
      			s=s+temp;
      		}
      		
        }
        return s;
    }


Matrix::Matrix ()
{	
	//cout<<"Please enter rows and cols number to make a matrix:";
	//cin>>rows>>columns;
	this->rows=0;
	this->columns=0;
	this->matrix=new float *[this->rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i]=new float [columns];
	}
	
}

Matrix::Matrix (int r, int c)
{
	this->rows=r;
	this->columns=c;
	this->matrix=new float *[r];
	for(int i=0;i<r;i++)
	{
		matrix[i]=new float [c];
	}
	
}

Matrix::Matrix(const Matrix & a)// copy constructor
{
	this->rows=a.rows;
	this->columns=a.columns;
	this->matrix=new float *[rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i]=new float [columns];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			this->matrix[i][j]=a.matrix[i][j];		
		}
	}
}

void Matrix::operator()(int i, int j, float val)//set value at (i,j)
{
	if(i<rows && j<columns)
	{
		if(i>0 && j>0)
		{
			this->matrix[i][j]=val;
		}	
		else
		{
			cout<<"Invalid index\n";
		}
	}	
	else
	{
		cout<<"Invalid index\n";
	}
}

Matrix& Matrix::operator=(const Matrix & a)//assigns (copies) a Matrix. Returns the same
{
	this->rows=a.rows;
	this->columns=a.columns;
	if(this->matrix!=NULL)
	{
		delete [] this->matrix;
	}
	this->matrix=new float *[rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i]=new float [columns];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			this->matrix[i][j]=a.matrix[i][j];		
		}
	}
return *this;	
}

bool Matrix::operator==(const Matrix & m)//Compares two matrices
{
	bool flag;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			if(matrix[i][j]==m.matrix[i][j])
			{
				flag=true;			
			}
			else
			{
				flag=false;
				break;
			}		
		}
		if(flag==false)
		{
			break;
		}
	}
	return flag;	
	
}

Matrix Matrix::operator+(const Matrix & m)//adds two Matrices and returns the result
{
		Matrix temp(rows,columns);
	if(this->rows==m.rows && this->columns==m.columns )
	{
		//temp.rows=this->rows;
		//temp.columns=this->columns;

		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				temp.matrix[i][j]=this->matrix[i][j]+m.matrix[i][j];		
			}
		}
	}
	else
	{
		cout<<"Addition can't be performed!!\n";
	}
	return temp;
}

Matrix Matrix::operator-(const Matrix & m)//adds two Matrices and returns the result
{
//Matrix temp1;
			Matrix temp1(rows,columns);
	if(this->rows==m.rows && this->columns==m.columns )
	{
	//temp1.rows=this->rows;
	//temp1.columns=this->columns;

		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				temp1.matrix[i][j]=this->matrix[i][j]-m.matrix[i][j];		
			}
		}
	}
	else
	{
		cout<<"Subtraction can't be performed!!\n";
	}
	return temp1;
}


Matrix Matrix::operator*(const Matrix &m)//multiplies two Matrices elementwise and returns,→ the result
{
	Matrix temp(this->rows,m.columns);
	if(this->columns==m.rows)
	{
		
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<m.columns;j++)
			{
				for(int k=0;k<this->columns;k++)
				{
					temp.matrix[i][j]+=this->matrix[i][k]*m.matrix[k][j];
				}
			}
		}
		return temp;
	}
	else
	{
		cout<<"Matrix Multiplication is not possible\n";
	}
	return temp;
	
}

Matrix& Matrix::operator++(int)//add one to every element
{
for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			matrix[i][j]+=1;		
		}

	}	
return *this;

}

void Matrix::operator+=(const Matrix& m)//adds two Matrices
{
	if(this->rows==m.rows && this->columns==m.columns )
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				this->matrix[i][j]+=m.matrix[i][j];		
			}
		}
	}
	else
	{
		cout<<"Addition can't be performed!!\n";
	}

}

void Matrix::operator-=(const Matrix& m)//subtracts two Matrices
{
	if(this->rows==m.rows && this->columns==m.columns )
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				this->matrix[i][j]-=m.matrix[i][j];		
			}
		}
	}
	else
	{
		cout<<"Subtraction can't be performed!!\n";
	}

}

Matrix::~Matrix()
{
//cout<<"Destructor Called!!!\n";
}

void Matrix::display()
{
for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<this->matrix[i][j]<<" ";		
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}
void Matrix::setvalue()
{
int r ,c;
cout<<"Please enter rows and cols number to make a matrix:";
cin>>r>>c;
rows=r;
columns=c;
if(matrix!=NULL)
{
	delete [] matrix;
}

this->matrix=new float *[this->rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i]=new float [columns];
	}
for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<"Eter value of element "<<i<<j<<endl;
			cin>>this->matrix[i][j];		
		}
	}
}


istream& operator>>(istream& input,Matrix &m)//Inputs the Array
{
	m.setvalue();
	return input;
}

ostream& operator<<(ostream& ouput,Matrix &m) //Outputs the Array
{
	m.display();
	return ouput;
}

int main()
{
/*
int r,c;
Matrix m1;
cin<<m1;
cout<<"\nChecking Patrameterized constructor\n";
cout<<"Enter the rows and cols:\n";
cin>>r>>c;
Matrix m2(r,c);
m2.setvalue();

cout<<"\nChecking Copy constructor\n";
Matrix m3(m1);

cout<<"\n***********Matrix Made************\n";
float val;
cout<<"\nEnter value of row and col and value to change\n";
cin>>r>>c>>val;
Matrix m4=m3;
m4(r-1,c-1,val);
cout<<"\n***********Matrix Made************\n";
m4.display();
cout<<"\nMaking a new Matrix = to above\n";
Matrix A =m4;

cout<<"\nChecking Matrix\n";
if(A==m4)
{
	cout<<"\nThey are equal\n";
}
else
{
	cout<<"\nThey are not equal\n";
}

cout<<"\n Adding two martices \n Matix 1:\n ";
m4.display();
cout<<"\n Matrix 2:\n";
A.display();

cout<<"\n*****SUM*******\n";
Matrix m5=m4+A;
m5.display();

cout<<"\n Subtracting two martices \n Matix 1:\n ";
m5.display();
cout<<"\n Matrix 2:\n";
A.display();

cout<<"\n*****Difference*******\n";
Matrix m6=m5-A;
m6.display();


cout<<"\n Multiplying two martices \n Matix 1:\n ";
m1.display();
cout<<"\n Matrix 2:\n";
m2.display();

cout<<"\n*****PRODUCT*******\n";
Matrix m7=m1*m2;
m7.display();

cout<<"\nTesting the increment operator\n";
m7++;
m7.display();


cout<<"\nAdding two matrices using += operator\nMatrix 1\n";
m1.display();
cout<<"\n Matrix 2:\n";
m2.display();

Matrix sum=m1+m2;
sum.display();


cout<<"\nSubtracting two matrices using -= operator\nMatrix 1\n";
sum.display();
cout<<"\n Matrix 2:\n";
m2.display();

sum-=m2;
cout>>sum;
*/

Matrix sum(2,2);
//cin>>sum;
//cout<<sum;
string a;
a=string(sum);
cout<<a;
//cout<<endl;
string s1="2X2\n0-0\n0-0";
cout<<s1;
return 0;
}


