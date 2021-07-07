#include <iostream>
using namespace std;

void countLetters ( char * string , int *&array , int & size )
{

array = new int [15];
	//calculating the length of string
	int countlen=0;
	for(int i=0;string[i]!='\0';i++)
	{
	countlen++;
	}

	//making an array to store chars according to the sequence in the string to avoide repeatition
	char lettersequence[15]={'#'};
		int pos=1,index=0;

	for(int i=0;i<countlen;i++)
	{
	bool flag=true;

			if(lettersequence[i]!=string[i])
			{
				for(int z=0;z<pos;z++)
				{
					if(lettersequence[z]==string[i])
					{
						flag=false;
					}


			    }
				if(flag==true)
				{
				 lettersequence[index]=string[i];
				 index++;
				 pos++;
				}
			}

	}
//initilizing array
	for(int init=0;init<index;init++)
	{
		*(array+init)=0;

	}
	//compare
	int arr=0;
	for(int i=0;i<index;i++)
	{
		 int repeat=0;
		 bool check=false;
		 for(int z=0;z<countlen;z++)
		 {
		  	if(lettersequence[i]==string[z])
		 	{
		 	    repeat++;
		 	    check=true;
		 	}
		 }
		 if(check==true)
		 {
		 	    array[arr]=repeat ;
		 	   arr++;

		 }

	 }



size=arr;


}
