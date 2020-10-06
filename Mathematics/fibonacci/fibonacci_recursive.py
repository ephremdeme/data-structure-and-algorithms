def fib_recursive(n):
    if n > 1:
        return fib_recursive(n-1) + fib_recursive(n-2)
    return n


if __name__ == '__main__':
    nums = int(input('How many fibonacci numbers:'))
    if nums < 2:
        print('Invalid nums')
    else:
        for i in range(nums):
            print(fib_recursive(i))