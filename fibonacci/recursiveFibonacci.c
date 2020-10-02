#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Fib_rec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return (Fib_rec(n - 1) + Fib_rec(n - 2));
    }
}

int main()
{
    int num;
    printf("Fibonacci number at n position: ");
    scanf("%d", &num);

    printf("%d\n", Fib_rec(num));
}
