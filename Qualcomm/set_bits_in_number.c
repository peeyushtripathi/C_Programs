#include<stdio.h>
int main()
{
    int num;
    int x=1;
    int count=0;
    printf("Enter a number: ");
    scanf("%d",&num);

    for(int i=0; i<32; i++)
    {
        if((num&x)==x)
        {
            count++;
        }

            x=x<<1;
    }
    printf("Number of bits set in %d is %d",num,count);

    return 0;
}