n = int(input("Enter the number of element : "))
arry = []
for i in range(n):
    j = int(input("Enter the element into array : "))
    arry.append(j)

# quick sort
def partition(arr, low, high):
    pivot = arr[low]
    i , j = low,high
    while arr[i]< pivot:
        i=i+1
    while arr[j] > pivot:
        j = j-1
    if(i<j):
        arr[i],arr[j] = arr[j],arr[i]

    arr[low],arr[j] = arr[j],arr[low]
    return j

    
def quickSort(low,high,arr):
    j = partition(arr,low,high)
    quickSort(low,j-1,arr)
    quickSort(j+1,high,arr)
quickSort(0,n-1,arry)















