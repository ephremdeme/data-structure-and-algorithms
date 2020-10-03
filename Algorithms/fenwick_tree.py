def construct_fTree(arr, n): 
    fTree = [0]*(n+1) 
    for i in range(n): 
        updateFTree(i, arr[i],fTree, n) 
    return fTree


def updateFTree(index ,val, fTree , n ): 
    index += 1 
    while index <= n: 
        fTree[index] += val
        index += index & (-index) 


def getSum(index, fTree): 
    sum = 0 
    index = index+1
    # Traverse ancestors of fenwick tree
    while index > 0: 
        sum += fTree[index] 
        index -= index & (-index) 
    return sum


def main():
    n = int(input('Enter the number of elements: '))
    arr = [int(x) for x in input('Enter the elements of array: '.format(n)).split()]
    fTree = construct_fTree(arr,len(arr))
    prefix=int(input('Enter the index for which you need prefix sum'))
    print(getSum(prefix,fTree))
    i,v=(input('Enter the index and its new value: ').split())
    i=int(i)
    v=int(v)
    updateFTree(i,v,fTree,n)
    prefix=int(input('Enter the index for which you need prefix sum'))
    print(getSum(prefix,fTree))
if __name__ == '__main__':
	main()