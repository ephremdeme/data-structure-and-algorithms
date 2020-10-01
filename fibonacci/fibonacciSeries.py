def fibonacciseries(n):
    if(n<=1):
        print(1)
    a, b = 1, 1
    print(a)
    while(b<=n):
        print(b)
        a, b = b, a+b

fibonacciseries(9)

