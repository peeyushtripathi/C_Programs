#include<stdio.h>
int main()
{
    int n;
    int j=1;
    scanf("Enter number %d",&n);
    n=n & 0xAAAAAAAA;
    printf("%d",n);
    return 0;
}