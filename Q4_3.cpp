#include <iostream>
using namespace std;
void countingUniqueWords ( char * string , char **&uwords , int *&array  , int & size  )
{
//Making a new 2d array that will be used for the comparision
	        char** arrcheck;
//calculating the number of words and length of string
int words=0,length=0;
for(int i=0;string[i]!='\0';i++)
{
	if(string[i]==' ')
	{
	  words++;
	}

	length++;
}
//initilizing the unique word array
        uwords=new char*[(words+1)];
        arrcheck=new char *[(words+1)];
        for(int i=0;i<(words+1);i++)
        {
	        uwords[i]=new char[10];
	        arrcheck[i]=new char[10];
        }
        for(int i=0;i<(words+1);i++)
        {
		 for(int j=0;j<10;j++)
		 {
		   uwords[i][j]='0';
		   arrcheck[i][j]='0';
		 }
        }

        array=new int[10];
        for(int i=0;i<10;i++)
        {
        array[i]=0;
        }

//storing string in the 2d array
int arr=0,numb=0;
for(int j=0;j<(words+1);j++,numb++)
{
	for(int i=0;i<length;i++)
	{
		if(string[numb]!=' ' && string[numb]!='\0' )
		{		if(string[numb]!='\n')
				{
		 			arrcheck[j][i]=string[numb];

				}
	 	     numb++;
	 	     if(string[numb-1]=='\n')
	 	     {
	 	    	 i=i-1;
	 	     }

		 }
		else
		{

			break;

		}

	}

}

//storing unique words in uwords array
int rows=1;
for(int i=0;i<(words+1);i++,numb++)
{
	int index=0,count=0;
	bool repeat=false , match=false , norep=false,allow=false;
	for(int j=0;j<10;j++)
	{
			if(i==0)
			{
				if(arrcheck[i][j]!='0')
				{
					uwords[i][j]=arrcheck[i][j];
				}

			}
			else
			{
				for(int row=0;row<i;row++)
				{
					for(int col=0 ; arrcheck[i][col]!='0';col++)
					{

						if( arrcheck[i][col]==arrcheck[row][col])
						{
							//if(norep==false)
							//{

							if(arrcheck[i][col-1]!=arrcheck[row][col-1])
							{
								allow=true;
								col=col+1;
							}
							else
							{
								repeat=true;
								match=true;

							}
							//break;
							//}
						}
						else
						{
							if(match==true && allow!=true)
							{
								break;
							}
							else
							{
							repeat=false;
							//norep=true;
							}
						}
					}
					if(match==true)
					{
						break;
					}
				}
				if(repeat==false)
				{
					for(int col=0 ; arrcheck[i][col]!='0';col++)
					{
						uwords[rows][col]=arrcheck[i][col];
					}
					rows++;
					break;
				}
			}
			if(match==true)
			{
				break;
			}
	}

}

for(int i=0;i<(words+1);i++)
        {
        bool yes=false;
        int calc=0;
		 //for(int j=0;j<uwords[i][j]!='\0';j++)
		 //{
			 for(int r=0;r<(words+1);r++)
			 {
				 yes=false;
				 for(int c=0;arrcheck[r][c]!='0';c++)
				 {
					 if(uwords[i][c]==arrcheck[r][c])
							   {
								   yes=true;
							   }
					 else
					 {
						 break;
					 }
				 }
				 if(yes==true)
				 {
					 calc++;
					 array[i]=calc;

				 }
			 }
		 //}
        }
size=rows;

}
