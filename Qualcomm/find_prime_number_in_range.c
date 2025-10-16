#include<stdio.h>
#include<stdbool.h>
bool isprime(int);
int main()
{
    int begin;
    int end;
    
    printf("enter:");
    scanf("%d",&begin);

    printf("enter:");
    scanf("%d",&end);

    for(int i=begin;i<=end;i++)
    {
        bool result=isprime(i);
        if(result==true)
            printf("%d==",i);
    }    return 0;
}

bool isprime(int i)
{
    for(int j=2;j<=i/2;j++)
    {
        if(i%j==0)
            return false;
    }
        return true;
}