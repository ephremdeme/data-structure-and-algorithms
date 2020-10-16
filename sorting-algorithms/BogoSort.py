# Bogo Sort in Python

import random

def isSorted(num):
    n = len(num)
    for i in range (0, n-1):
        if(num[i] > num[i+1]):
            return False
    return True

def bogoSort(num):
    n = len(num)
    while(isSorted(num)==False):
        global counter
        shuffle(num)
        counter += 1

def shuffle(num):
    n = len(num)
    for i in range (0,n):
        r = random.randint(0,n-1)
        num[i],num[r] = num[r],num[i]

# Shuffle Counter
counter = 0

# Array/list size
print("Enter the size of list/array : ")
size = int(input())
num = []

for i in range(0,size):
    print("Enter element number ", i+1)
    added = int(input())
    num.append(added)

bogoSort(num)
print("Sorted number (increasing) : ")
print(num)
print("Number of shuffle : ", counter)

