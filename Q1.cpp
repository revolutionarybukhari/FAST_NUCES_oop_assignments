#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class data   //class of data of rectangle is created
{
//private data members
int n; //number of rectangles
int **ptr;//it stores the coordinates of a rectangle
double *areas;//it stores the area of the rectangles
int *list;
double *copy_array;

public:

data ()//default constructor
{
}

void setn(int no) //set the value of n
{
this->n=no;
}

void rectangleGenerator (int n )//created a dynamical array for the coordinates
{
srand(time(0));
ptr=new int *[n];
for(int i=0;i<n;i++)
{
	ptr[i]=new int[8];
}


for(int i=0;i<n;i++)       // for each rectangle generated the coordinates are taken from the user and stored
{

int x1=(rand()%20 )+1;
int y1=(rand()%20 )+1;
int length=(rand()%30 )+1;
int width=2*((rand()%30 )+1);
while(length==width)
{
width=(rand()%30 )+1;
}

//cout<<"Enter cordinates of rectangle "<<i+1<<" one by one!"<<endl;
//cout<<"Enter coordinate by coordinate X then Y for all four coordinates"<<endl;
	ptr[i][0]=x1;
	ptr[i][1]=y1;
	
	ptr[i][2]=x1+width;
	ptr[i][3]=y1;
	
	ptr[i][4]=x1;
	ptr[i][5]=y1-length;
	
	ptr[i][6]=x1+width;
	ptr[i][7]=y1-length;
	
	

}

}

double *sort() //it use search and sort technique to sort the area array
{
int tmp;
for(int i=0; i<n; i++)
    {
        for(int  j=i+1; j<n; j++)
        {
            if(areas[j] <areas[i])
            {
                tmp = areas[i];
                areas[i] = areas[j];
                areas[j] = tmp;
            }
        }
    }
return areas;
}

double * area()  //it uses the area formula to calculate the area of the rectangle for each rectangle and store them in the array and the array is returned
{

	areas =new double [n];
	copy_array=new double[n];
	
	for(int i=0;i<n;i++)
	{
	int x1=this->ptr[i][0];
	int x2=this->ptr[i][2];
	int y1=this->ptr[i][1];
	int y3=this->ptr[i][5];
	 areas[i] =(x2-x1)*(y1-y3);
	this-> copy_array[i]=(x2-x1)*(y1-y3);
	}

return areas;
}

void displaycoordinates()
{
for(int i=0;i<n;i++)
{

//cout<<"Enter coordinate by coordinate X then Y for all four coordinates"<<endl;
	cout<<"("<<ptr[i][0]<<","<<ptr[i][1]<<")"<<" ";
	cout<<"("<<ptr[i][2]<<","<<ptr[i][3]<<")"<<" ";
	cout<<"("<<ptr[i][4]<<","<<ptr[i][5]<<")"<<" ";
	cout<<"("<<ptr[i][6]<<","<<ptr[i][7]<<")"<<endl;

}


}

 bool overlapping(int *largest,int *overlap)
 {
       if (largest[5]==largest[3]||largest[6]==overlap[4]||overlap[5]==overlap[3]||overlap[6]==overlap[4]) 
       {
       
       return false;
       }

//comparison for the overlap
       if (largest[5]>=overlap[3] || overlap[5]>=largest[3])
       {
       return false;
           }

       if (largest[6]<=overlap[4] || overlap[6]<=largest[4])
       {
           return false;
           }

       return true;
       }

 int **calc( )
 {	int counter=0;
 	int position=0;
 	//finding largest rectangle position
 	for(int i=0;i<n;i++)
 	{
 		if(areas[n-1]==copy_array[i])
 		{
 			position=i;
 			break;
 		}
 	}
 
 	
	int **array;
	array= new int* [n];
	for(int i=0;i<8;i++)
	{
		array[i]=new int[8]; 
	}
	int ptr2[10]={0};
	int largest_rec[8]={0};
	for(int i=0;i<8;i++)
	{
		largest_rec[i]=ptr[position][i];
	}
	
	for(int i=0;i<this->n;i++)
	{
		for(int j=0;j<8;j++)
		{
			ptr2[2]=ptr[i][j];
		}
		for(int b=0; b<8; ++b)
		{
			if(overlapping(largest_rec,ptr2))
			{
				array[i][b]= ptr2[b];
				counter++;
			}
		}
		
	
	}
	
	
	
	
	cout<<"\nNumber of overlapping rectangles are: "<<counter<<endl;
	return array;
}

};

int main()
{
int n;
double *ptr;
data rec;

cout<<"Enter number of rectangles:"<<endl;
cin>>n;

rec.setn(n);
rec.rectangleGenerator(n);
rec.displaycoordinates();

ptr=rec.area();


for(int i=0;i<n;i++)
{
cout<<"area of rectangle "<<i<<" :"<<ptr[i]<<endl;
}
cout<<"area sorted"<<endl;
ptr=rec.sort();
for(int i=0;i<n;i++)
{
cout<<"area of rectangle "<<i<<" :"<<ptr[i]<<endl;
}
cout<<endl;
int **array;
array=rec.calc();


/*   for(int i=0;i<n;i++)
   {
       cout<<"Number of overlaps of rectangle "<<(i+1)<<" is "<<rec.overlap(i)<<endl;
   }
*/

return 0 ;
}
