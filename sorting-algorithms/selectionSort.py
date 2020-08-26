arr = [4, 1, 3, 5, 2]

for i in range(len(arr)):
    k = i
    for j in range(i+1, len(arr)):
        if(arr[j] < arr[k]):
            k = j
    arr[i], arr[k] = arr[k], arr[i]

    print(arr, i) #Just to steps of each iterations

print(arr) #[1, 2, 3, 4, 5]
