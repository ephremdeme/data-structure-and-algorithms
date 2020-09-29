def ShellSort(arr):
    n = len(arr)
    gap = n / 2
    gap = int(gap)

    while(gap > 0):
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while(j >= gap and arr[j - gap] > temp):
                arr[j] = arr[j - gap]
                j -= gap
            
            arr[j] = temp
        gap //= 2


if __name__ == "__main__":
    arr = [int(item) for item in input().split()]   
    ShellSort(arr)
    print(arr)