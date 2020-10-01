n = 1005
result = 0
while n!=0:
    result = result * 10 + (n%10)
    n = n//10
print(result)
# Time complexity: O(n)
# Code contibuted by Manan Chawla