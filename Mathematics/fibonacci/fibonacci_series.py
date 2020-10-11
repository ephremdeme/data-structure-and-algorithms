def fibonacci(n):
    if n<=2:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)
        
n = int(input('Enter a number (greather than 2): '))

for val in range(1,n-1):
    print(fibonacci(val), end = ', ')
