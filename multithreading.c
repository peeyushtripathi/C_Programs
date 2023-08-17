#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mu;
void* thread_fun1()
{
	while(1)
	{
		pthread_mutex_lock(&mu);
	printf("inside fun1\n");
	pthread_mutex_unlock(&mu);
	sleep(2);
	}
}
void* thread_fun2()
{
	while(1)
	{
	pthread_mutex_lock(&mu);
	printf("inside fun2\n");
	pthread_mutex_unlock(&mu);
	sleep(2);
	}
}



int main()
{
	pthread_t p1,p2;


	pthread_create(&p1,NULL,thread_fun1,NULL);
	pthread_create(&p2,NULL,thread_fun2,NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	printf("inside: main\n");
	return 0;
}
