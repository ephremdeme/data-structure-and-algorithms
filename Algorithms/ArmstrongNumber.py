def check_armstrong_num(n):
    sum_of_cubes = 0
    orig_n = n
    while n > 0:
        digit = n%10
        sum_of_cubes = sum_of_cubes + pow(digit, 3)
        n = n//10
    
    if sum_of_cubes == orig_n:
        return "Is an Armstrong Number"
    else:
        return "Not an Armstrong Number"

number = int(input())
result = check_armstrong_num(number)
print(result)
