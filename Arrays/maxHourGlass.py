# This python3 script accepts a nxn two dimensional matrix
# and calculates the maximum hourglass sum possible from it.

'''
Example:
In this 6x6 Matrix:

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 1 1 1
0 0 0 0 1 0
0 0 0 1 1 2

The pattern:
1 1 1
0 1 0
1 1 1

makes 1 hour glass. And the sum of this hour glass is:
1 + 1 + 1 + 1 + 1 + 1 + 1 = 7
Similarly we need to find sum of all hourglasses in the Matrix
And print the maximum sum.
'''

#Taking rank of the matrix from user
n = int(input())
l = []

#Converting each string of row values into list and appending it to The
#main two dimensional list 'l'
for i in range(n):
    il = list(map(int, input().split()))
    l.append(il)

#This will store our expected result
finalSum = 0

#Creating a 3x3 grid index to iterate over the two dimensional list And
#calculate sum of the hourglasses.
#-2 is added to make sure not to index beyond the actual list range.
for r1 in range(n-2):
    r2 = r1+1
    r3 = r2+1
    for c1 in range(n-2):
        #to store sum of all hourglasses
        res = 0
        c2 = c1+1
        c3 = c2+1
        res = l[r1][c1] + l[r1][c2] + l[r1][c3] + l[r2][c2] + l[r3][c1] + l[r3][c2] + l[r3][c3]
        #Maybe the first element is -ve, therefore need to store it no matter what.
        if r1 == 0 and c1 == 0:
            finalSum = res
        #will always store the maximum result
        if res > finalSum:
            finalSum = res

#print the maximum hourglass sum.
print(finalSum)
