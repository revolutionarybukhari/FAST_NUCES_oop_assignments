#include <iostream>

using namespace std ;

int Strlen ( char * s1 )
{
int counter=0;
for(int i=0;*(s1+i)!='\0';i++)
{
 counter++;
}

return counter+1;
}

