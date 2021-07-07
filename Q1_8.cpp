#include <iostream>

using namespace std ;
char **StrTok ( char *s1 , const char s2 )
{
int counter=0,length=0;
int count=0;
int position=0;
for(int i=0;*(s1+i)!='\0';i++)
	{
	  if(*(s1+i)==s2)
	  {
	  counter++;
	  position=6;

	  }
	  length++;
	}
char **ptr=new char *[counter+1];

for(int i=0;i<(counter+1);i++)
{
	  ptr[i]=new char [position];

}
int location=0;
for(int i=0;i<(counter+1);i++)
{
int c=0;
	for(int j=location;j<(length+1);j++)
	{
	if(s1[j]==s2)
	 {
	 location=j+1;
	 ptr[i][j]='\0';
         break;
         }
         else
         {
         ptr[i][c]=s1[j];

         }
	c++;
	}
}

return ptr;
}

