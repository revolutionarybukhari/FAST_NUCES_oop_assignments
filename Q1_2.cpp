#include <iostream>

using namespace std ;

char *Strcpy ( char *s1 , const char *s2 )
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

s1=new char[sizes2];

for(int i=0;i<sizes2 ;i++)
{
s1[i]=s2[i];

}
s1[sizes2]='\0';




 	return s1;
}
