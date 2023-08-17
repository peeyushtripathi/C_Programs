#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	int id=fork();
	if(id ==0)
		printf("as id =0 child child\n");
	else
		printf("as id =%d inside parent\n",id);

	printf("this will be printed by both\n");
	return 0;
}

