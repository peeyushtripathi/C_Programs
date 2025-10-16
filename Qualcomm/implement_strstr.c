#include<stdio.h>
int main()
{
   char str1[200],str2[10];
   char *str1_ptr=NULL;
   char *str2_ptr=NULL;
   int str1_count=0;
   int str2_count=0;
   printf("Enter main string :");
   scanf("%s",str1);
    printf("Enter main string :");
   scanf("%s",str2);
    int i=1;
   while(str1[i]!='\0')
   {
        str1_count++;
        i++;
   }
   i=1;
      while(str2[i]!='\0')
   {
        str2_count++;
        i++;
   }
   str1_ptr=(char *) malloc(sizeof(char)*(str1_count+1));
   str2_ptr=(char *) malloc(sizeof(char)*(str2_count+1));

   mystrncpy(str1,str1_ptr,str1_count+1);
   mystrncpy(str2,str2_ptr,str2_count+1);


   printf("first %s\n",str1_ptr);
   printf("second %s\n",str2_ptr);

   int counter=0;
   int j=0;
   i=0;
   for(;i<str2_count;)
   {
    int ptr=j;
    j=counter;
    while(str1_ptr[j]==str2_ptr[i])
    {
        printf("i=%d, j=%d\n",i,j);
        i++;
        j++;
        
    }
    if(str2_ptr[i]=='\0')
    {
        printf("ptr is %d",++ptr);
    }
    else
    {
        counter++;
    }


   }
    return 0;
}

void mystrncpy(char *source, char *target, int size)
{
    int i=0;
    for(;i<size;i++)
    {
        target[i]=source[i];
    }
    target[i]='\0';
}