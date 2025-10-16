#include<stdio.h>
int main()
{
    int a;
    int b;
    int c;
    int count=0;
    printf("first:");
    scanf("%d",&a);
    printf("second:");
    scanf("%d",&b);
    c=a^b;
    printf("xor is %d",c);
    for(int i=0;i<32;i++)
    {
        if((c&1)==1)
        {
            count++;
        }
        c=c>>1;
    }
    printf("counter=%d",count);
    return 0;
}