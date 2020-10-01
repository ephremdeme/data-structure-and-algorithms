#include<stdio.h>
int f(int n);
void main()
{
    int n;
    scanf("%d",&n);
    int sum=f(n);
    printf("\n%d",sum);
}
int f(int n)
{
    if(n==1)
    {
        return 1;
    }
    return (n*f(n-1));
}
