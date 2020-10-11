def theupdate(index, a, tree, value):
# index is index to be theupdated, a is input array / list, tree is BIT array, value is value to be added to original 
# number at index location
    add = value
    n = len(a)
    while index<n:
        tree[index] += add
        index = index + (index & (-index))

def getsum(index, a, tree):
# index is location upto which you want the sum of elements from beginning
# tree is BIT[], a is input array / list
    n = len(a)
    ans  = 0
    while(index>0):
        ans += tree[index]
        index = index - (index & (-index))
    return ans

#Get the user input
n = int(input("Number of Elements in array: "))
inputArray = list(map(int, input("Elements in array: ").split()))
inputArray.insert(0,0)                 # insert dummy node to have 1-based indexing

#Initialise Binary Indexed Tree to 0's considering that input array is all 0's
BIT = []
for i in range(0, n):
    BIT.append(0)

# Now we will construct actual BIT
# The 4th parameter is always an additional value which is to be added to element at index location
# since we have considered input array as 0 earlier (while initialising BIT), for updating, we will pass actual 
# value
for i in range(1, n):
    theupdate(i, inputArray, BIT, inputArray[i])