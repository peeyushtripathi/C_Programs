#include<stdio.h>
int main()
{
    int one=0;
    int two=0;
    int zero=0;
    int arr[10]={0,1,2,2,1,0,1,2,0,1};

        for( int i=0;i<10;i++)
        {
            if(arr[i]==0)
            {
                zero++;
            }
            else if(arr[i]==1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        for(int i=0;i<zero;i++)
        {
            arr[i]=0;
        }
        for(int i=zero;i<zero+one;i++)
        {
            arr[i]=1;
        }
        for(int i=zero+one;i<10;i++)
        {
            arr[i]=2;
        }

        for(int i=0;i<10;i++)
        {
            printf("%d ",arr[i]);
        }   
    return 0;
}