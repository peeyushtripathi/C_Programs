#include<stdio.h>
#include<stdlib.h>

void window_logic(int *arr, int N, int K)
{
    int max=0;
    int sum=0;
    int begin=0;
    for(int i=0;i<K;i++)
    {
        sum=sum+arr[i];
    }
    max=sum;
    printf("max==%d\n",max);
    for(int i=1;i<N-K;i++)
    {
        sum=sum-arr[i-1]+arr[K-1+i];
        if(sum>max)
        {
            max=sum;
            begin=i;
        }
        printf("at i==%d..max==%d\n",i,max);
    }

    printf("max sum for size %d is %d ..it begins with index =%d",K,max, begin);
}
int main()
{
    int N=0;
    int K=0;
    printf("enter elements you will enter\n");
    scanf("%d",&N);
    printf("enter windows size:");
    scanf("%d",&K);
    int *arr=(int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("DONE !! ");

    window_logic(arr, N, K);
    return 0;
}