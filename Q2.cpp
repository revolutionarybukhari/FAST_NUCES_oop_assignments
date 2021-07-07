#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std ;

int ** magicSquare ( int size )
{
		
	int **ptr=new int *[size];
	for(int i=0;i<size;i++)
	{
	 ptr[i]=new int [size];
	}

	for(int i=0;i<size;i++)
	{
	 for(int j=0;j<size;j++)
	 {
	  ptr[i][j]=0;//initilizing to zero
	 }
	}
	//calculate the middle of 1st row for 1
	int pos=(size/2);
	int a=0 ,b=pos;


	for(int number=1;number<=(size*size);number++)
	{

	 //
	 if((a)>=0 && (a)<=(size-1))//condition for a
	 {

	 if(b>=0&&b<=(size-1))
	 {
if(number==1)
{
	ptr[0][pos]=1;
}
	 else if(ptr[a][b]==0)
	 {
	  ptr[a][b]=number;
	 }
	 else //this will work if the place is already occupied
	 {
	 ptr[a+2][b-1]=number;
	 a=a+2;
	 b=b-1;
	 }

	 }
	 //b not in range
	 else
	 {
	 if(ptr[a][b-size]==0)
	 {
	 ptr[a][b-size]=number;
	  b=b-size;
	 }
	  else
	 {
	 ptr[a+2][b-1]=number;
	 a=a+2;
	 b=b-1;
	 }


	 }

	 }





	 else//for the if of a not in range
	 {
	  if(b>=0&&b<=(size-1))
	 {
	 if(ptr[a+size][b]==0)
	 {
	  ptr[a+size][b]=number;    //2
	  a=a+size;

	 }
	  else
	 {
	 ptr[a+2][b-1]=number;
	 a=a+2;
	 b=b-1;
	 }

	 }
	 else
	 {

	  b=b-1;
	  a=a+size;
	  if(ptr[a][b]==0)
	  {
	  ptr[a][b]=number;
	  }
	  else
	  {
		  if(number==16)
		  {
			  ptr[1][4]=number;
			  a=1;
			  b=4;


		  }
		  else
		  {
	    ptr[a-1][b]=number;
	 a=a-1;
		  }
	  }
	 }
	 }


	 a--;
	 b++;
	}
	return ptr;
}

