
# The insertion sort works just like its name suggests—it inserts each item into its proper
# place in the final list

arr = [4, 7, 3, 5, 2,9, 6, 8, 1]
for i in range(1, len(arr)):
    temp = arr[i]
    j = i
    while((j > 0) and (arr[j-1] > temp)):
        arr[j] = arr[j-1]
        j = j-1
    arr[j] = temp
    print(arr, i) # just to show what happens in each iterations


print(arr)  #[1, 2, 3, 4, 5, 6, 7, 8, 9]

