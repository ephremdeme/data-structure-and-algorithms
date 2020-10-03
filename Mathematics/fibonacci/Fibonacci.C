#include<stdio.h>
#include<conio.h>
int fibonacci(int);
int main()
{
 int n,i,c=0,res=0;
 clrscr();
 printf("Enter the value of n: ");
 scanf("%d",&n);
 printf("The terms are: \n");
 for(i=1;i<=n;i++)
 {
  res=fibonacci(c);
  printf("%d ",res);
  c++;
 }
 getch();
 return 0;
}
int fibonacci(int x)
{
 if(x==0 || x==1)
  return x;
 else
  return fibonacci(x-1)+fibonacci(x-2);
}