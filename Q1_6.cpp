#include <iostream>

using namespace std ;

int StrCmp ( const char *s1 , const char *s2 )
{
int value;
signed int i=0;
        while(*(s1+i)!='\0'|| *(s2+i)!='\0')
       {       
            //for(int j=0;*(s1+j)== *(s2+j);j++)
            //{
  		          
            //}
        
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
