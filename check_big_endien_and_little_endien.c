#include<stdio.h>

void show_memory(char *start, int size)
{
	int j=0;
	for(j=0;j<size;j++)
		printf("%.2x ",start[j]);

	printf("\n");

// if output is 67 45 23 01 the its little endien
// if output is 01 23 45 67 then its big endien

}
int main()
{
	int i=0x01234567;
	show_memory((char *)&i, sizeof(i));
	getchar();
	return 0;
}
