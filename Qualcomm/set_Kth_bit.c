#include<stdio.h>
int main()
{
    int N,K;
    printf("Enter N and K: ");
    scanf("%d %d",&N,&K);
    N=N|(1<<(K-1));
    printf("Number after setting Kth bit: %d",N);
    return 0;
}