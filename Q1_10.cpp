#include <iostream>

using namespace std ;

char * SubStr ( char * s1 , int pos , int len )
{
	char *ptr=new char [len+1];
	for(int i=0;i<len && s1[i]!='\0';i++)
	{
	 ptr[i]=s1[pos];
	 pos++;
	}
	ptr[len+1]='\0';
	
	
	
	return ptr;
	
}
