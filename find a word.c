#include<stdio.h>
void main()
{
  char s[100];
  char f[20];
  printf("enter a sentence..\n");
  gets(s);
  puts("enter a word that needs to be searched..");
  gets(f);
  int ls = strlen(s);
  int lf = strlen(f);
  printf("%d\n%d",ls,lf);

}
