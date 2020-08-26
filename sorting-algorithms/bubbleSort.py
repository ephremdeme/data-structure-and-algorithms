#Bubble Sort
# The bubble sort works by comparing each item in the list with the item next to it and
# swapping them if required.

arr = [4, 7, 3, 5, 2,9, 6, 8, 1]

for i in range(len(arr)-1):
    for j in range(len(arr)-i-1):
        if(arr[j]>arr[j+1]):
            arr[j], arr[j+1] = arr[j+1], arr[j]
    print(arr) # just to show steps during sorting

print(arr) # sorted arrays

    