def Fibonacci():
    statement = int(input("Please enter the number of Fibonacci numbers to generate: "))
    i = 1
    fib_list = []

    if statement == 0:
        fib_list = []
    elif statement == 1:
        fib_list = [1]
    elif statement == 2:
        fib_list = [1, 1]
    elif statement > 2:
        fib_list = [1,1]
        while i < (statement -1):
            fib_list.append(fib_list[i]+fib_list[i-1])
            i += 1

    print(fib_list)

Fibonacci()