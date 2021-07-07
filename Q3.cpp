#include <iostream>

using namespace std ;

char *convertToMorseCode ( char * s )
{
	const char letters[38] = {' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' ,'!'};
	const char *morseLetters[38] = {"/",".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",  "--", "-.", "---", ".---", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----","-.-.--"};

	//array made
	char *ptr= new char [70];


	 //store
	 int j=0;
	for(int i=0;i<22;i++)
	{
	 //for(int j=0;j<15;j++)
	 //{
	 for(int k=0;k<38;k++)
	 {
	 	if(s[i]==letters[k])
	 	{
	 		for(int n=0;*(*(morseLetters+k)+n)!='\0';n++)
		 	{
		    	 ptr[j]=*(*(morseLetters+k)+n);
		    	 j++;
		    	  if(*(*(morseLetters+k)+n+1)=='\0' && s[i]!=' ')
			 		 {
		    		  if(s[i+1]!='\0')
		    		  {
						 if( s[i+1]!=' ')
						 {
						 ptr[j]=' ';
						 j=j+1;
						 }
		    		  }
			 		 else if(s[i+1]=='\0')
			 		 {
			 			 ptr[j]='/';
			 			 j++;
			 		 }

					 //j++;
			 		break;

			 		 }

		 	}
		 	break;
	 	}

	 //}
	 }


	 }
	return ptr;
}


char *convertToString ( char * s ) 
{
const char letters[38] = {' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' ,'!'};
const char *morseLetters[38] = {"/",".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",  "--", "-.", "---", ".---", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----","-.-.--"};

//array for decoded words
char *p=new char[23];
//calculating the length of string
int length=0,word=0;
for(int i=0;s[i]!='\0';i++)
{
	if(s[i]==' ')
	{
		word++;
	}
	length++;
}
//making a 2d array for storing the code in array row by row
char **ptr=new char *[24];
for(int i=0;i<24;i++)
{
ptr[i]=new char[7];
}

//storing the code char by char in row by row order
int index=0;
for(int i=0;i<24;i++)
{
	for(int j=0;s[index]!=' ' || s[index]=='\0';j++)
	{
		if(s[index]=='/')
		{
			ptr[i][j]=s[index];
			index++;
			break;
		}

		ptr[i][j]=s[index];
		index++;
		if(s[index]=='/')
			{
				break;
			}
		if(s[index]==' ' || s[index]=='\0')
		{
			index++;
			break;
		}
	}


}

for(int i=0;i<24;i++)
{
	int start=0;
	bool flag=false,confirm=false;
 for(;start<38;start++)
 {bool first=false;
	 for(int h=0;ptr[i][h]!='\0' && morseLetters[start][h]!='\0' ;h++)
	 {
		 if(ptr[i][h]==morseLetters[start][h])
		 {
			 flag=true;
			 //j++;
			 if(ptr[i][h+1]==morseLetters[start][h+1])
			 {
				 if(morseLetters[start][h+1]=='\0' && first==false)
				 {
					 confirm=true;
					 break;
				 }
			 }
		 }
		 else
		 {
			 flag=false;
			 first=true;


		 }
	 }
	 if(confirm==true)
	 {
		 break;
	 }
 }
 if(flag==true && confirm==true)
 {
	 p[i]=letters[start];
 }

} 
   return p;

}

