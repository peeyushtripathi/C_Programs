#include<stdio.h>
int main()
{
    char a;
    char b;
    printf("Enter a character: ");
    scanf("%c",&a);
    b=a;
    printf("%x===>",a);
    a=a&0x0F;
    b=b&0xF0;
    a=a<<4;
    b=b>>4;
    a=a|b;
    printf("After swapping nibbles: %c",a);
    return 0;
}