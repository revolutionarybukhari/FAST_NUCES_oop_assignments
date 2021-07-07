#include <iostream>
using namespace std;
void countWordsBasedOnLength ( char * string , int *&array  , int &size )
{
	array = new int [10];
	  for(int i=0;i<10;i++)
	  {
	  array[i]=99;
	  }
	  //counting length and spaces
	  int length=0,spaces=0;
	  for(int i=0;string[i]!=0;i++)
	  {
		   if(string[i]==' ')
		   {
			   spaces++;
		   }

		   length++;
	  }

	 //spaces at 0 index
	 array[0]=spaces;

	 //calculating the number of words by length
	 int q=0,a=0;
	 int max=0,start=0;
	 for(int j=0;j<(spaces+1);j++)
	 {
	 int size1 =0;
		 for(;start<length;)
		 {
			if(string[start]!=' ' && string[start]!='\0')
			{

			 size1++;
			 start++;
			}
			else
			{
			start++;
			break;
			}
		 }
		 if(max<size1)
		 {
		 	max=size1;
		 }
		 if(size1!=0)
		 {
			 if(array[size1]!=99)
			 {

				 a=array[size1];
				 a=a+1;
				 array[size1]=a;

			 }
			 else if(array[size1]==99)
			 {
				 array[size1]=1;
			 }
		 }
		 //max length for size +1


	 }
	   for(int i=0;i<10;i++)
	  {
	  	if(array[i]==99)
	  	{
	  	array[i]=0;
	  	}

	  }
	  size=max+1; 
}
