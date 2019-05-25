#include<stdio.h>
#include<cstdlib>
int main()
{
    int len = 0;
    int r[] = {5,3,6,8,5,6,3,8,5,3,6,8,9};
    len = sizeof(r)/sizeof(int);
    int temp;
    int cnt = -1;

    for(int i=0;i<=len;i++)
    {
        temp = r[i];
        for(int j=0;j<=len;j++)
        {
            if(temp==r[j])
                cnt++;
        }
        if(cnt==1)
        {
            printf("The one element is: %d",temp);
            exit(0);
        }
        cnt = -1;
    }

}
