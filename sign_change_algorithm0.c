#include<stdio.h>
#include<stdlib.h>

int main()
{
    int len;
    printf("Enter the length: ");
    scanf("%d",&len);
    int r[len];

    printf("Enter the sequenge:\n");
    for(int i=0;i<=len;i++)
    {
        scanf("%d",&
        r[i]);
    }

    for(int i=0;i<=len;i++)
    {
        if(((r[i]<0)&(r[i+1])>0)|((r[i]>0)&(r[i+1]<0)))
            printf("sign change at %d",i);
    }
}
