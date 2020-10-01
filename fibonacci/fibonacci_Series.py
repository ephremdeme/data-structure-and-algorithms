# Program to display the Fibonacci Series

terms = int( input("Enter the term : ") )

# first two terms 
n1, n2 = 0, 1
count = 0

print("the Fibonacci Series is - \n")

while count < terms:
    print(n1)
    nth = n1 + n2
    n1 = n2
    n2 = nth
    count += 1