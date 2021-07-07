#include <iostream>

using namespace std ;

char *StrnCat ( char *s1 , const char *s2 , size_t n )
{
//determining size of arrays
int counter=0 , counter1=0;
int sizes1,sizes2;
while(*(s1+counter)!=0)
{
counter++;

}
while(*(s2+counter1)!=0)
{
counter1++;

}
//so the total size including '\0'will be  counter +1
sizes1=counter+1;
sizes2=counter1+1;
char *start=s1;
s1=new char[sizes2+sizes1];
int k=0;

for(int i=0;i<=(sizes1+sizes2) ;i++)
{
	if(i<(sizes1-1))
	{
	s1[i]=start[i];
	}

	if(i>=(sizes1-1) && i<=(sizes1+n+1))
	{
	s1[i]=s2[k];
	k++;
	}

}
s1[sizes1+sizes2-1]='\0';




 	return s1;

}
