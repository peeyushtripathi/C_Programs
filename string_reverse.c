#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
	char *str ="I LOVE INDIA";
	char *bkp=str;
	int length = strlen(str);
	int number_of_blanks=1;
	int word =0;
	for (int i=0;i<length;i++)
		if(bkp[i]==' ')
                     number_of_blanks++;

	//printf("number of blanks ==%d",number_of_blanks);
	char ** pptr=(char **) malloc(sizeof(char *)*number_of_blanks);

	for(int i=0 ; i<length ; i++)
	{
		if(i==0)
		{
		    pptr[word]=&bkp[0];
		    word++;
		}
		if(bkp[i]==' ')
		{
		    pptr[word]=&bkp[i+1];
		    word++;
		}

	}
	for(int i=number_of_blanks-1; i>=0; i--)
	{
		//printf("initial   ...%s ======> i\n",pptr[i]);
		int j=0;	
			while((pptr[i][j])!=' ')
			{

				if(pptr[i][j]==0)
					break;
				//printf("i ==%d, j==%d ===",i,j);
				printf("%c",pptr[i][j]);
				//printf("   ascii===>%d",pptr[i][j]);
				j++;
			}
				printf("\n");
			
		
	}

	return 0;
}
