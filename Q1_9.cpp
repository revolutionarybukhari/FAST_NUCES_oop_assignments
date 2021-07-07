#include <iostream>

using namespace std ;
int StrFind ( char *s1 , char *s2 )
{
//calculating the number of words in s1
	int words=0,length=0;
	for(int i=0;*(s1+i)!='\0';i++)
	{
		 if(*(s1+i)==' ')
		 {
			  words++;
		 }
		 length++;
	}
	//char ptr[(words+1)][(length/2)];
	char **ptr=new char* [(words+1)];
	for(int i=0;i<(words+1);i++)
	{
		ptr[i]=new char[(length/2)];
	}

	//making a 2d array
	int a=0;
	for(int i=0;i<(words+1);i++)
	 {
		for(int j=0;*(s1+a)!='\0';j++)
		{
			if(*(s1+a)!=' ')
			{
				ptr[i][j]=s1[a];
				a++;
			}
			else
			{
				a++;
			 break;
			}
		}
	 }

	//comparing
	int counter=0,repeat=0;
	bool check=false;
	for(int i=0 ; i<(words+1);i++)
	{
	//bool check=false;
		for(int j=0;*(s2+j)!='\0';j++)
		{
		  if(*(s2+j)==ptr[i][j])
		  {
			 
		    check=true;
			  

		  }
		  else if(ptr[i][j]!=*(s2+j))
		  {
		  	check=false;
		    counter++;
		  }
		}

		if(check==true)
		{

		 repeat++;
		}
	}
	if(repeat<=1)
	{
		if(check==true)
		{
			counter=counter+2;
			return counter;
		}
		else if(check==false)
		{
			return -1;
		}
	}
	else
	{
	return 0;
	}


return counter;
}

