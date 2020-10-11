# Finding HCF (GCD) and LCM using Recursive Function

# Defining function

def hcf(a,b):
    if b==0:
        return a
    else:
        return hcf(b, a%b) # this is recursion as hcf() calls itself

# Reading numbers from user
first = int(input('Enter first number: '))
second = int(input('Enter second number: '))

# Function call & displaying output HCF (GCD)
print('HCF or GCD of %d and %d is %d' %(first, second, hcf(first, second)))
print('LCM of %d and %d is %d' %(first, second, first*second/hcf(first, second)))