#include <iostream>

using namespace std ;

int StrnCmp ( const char *s1 , const char *s2 , size_t n )
{
	
int value;
signed int i=0;
        while(*(s1+i)!='\0'|| *(s2+i)!='\0')
       {       
            if(i==n)
            {
            break;
            }
        
        if(*(s1+i)== *(s2+i))
        {
        value=0;

         
        }
        
        if(*(s1+i) < *(s2+i))
        {
return -1;
        }
        
        if(*(s1+i) > *(s2+i))
        {

         return 2;
        }
        
        i++;
        }
        
        return value;

}
