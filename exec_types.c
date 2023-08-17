#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
	int proc=0;

	if(fork()==0)
	{
		printf("inside child\n");
		char *path="/bin/ls";
		char *arg1="-la";
	//	char *arg2="*";
		char *no_absolute_path_needed="ls";

		///********************1******************
		//execl(path, path, arg1, /*arg2,*/ NULL);//absolute path
		//
		//
		//*************************2*******************************
	//	execlp(no_absolute_path_needed,no_absolute_path_needed, arg1, /*arg2,*/ NULL);//checks in PATH
	//
	//	//**********************3********************************************
	//	v waalo mai alag alag argument dene ki zarurat nhi hai
//		char *argv[] ={path, "-la", NULL};
//		execv(path, argv);//everything in char * array as one parameter with full path
				  
		//*********************4*******************************************
		char *argv[] ={no_absolute_path_needed, "-la", NULL};
		execvp(path, argv);//everything in char * array as one parameter with full path

	}
	else
	{
		printf("inside parent\n");
	}
	return 0;
}
