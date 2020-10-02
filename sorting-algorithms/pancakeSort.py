# Python code of Pancake Sorting Algorithm

def maxNum(arr, size):

    num = 0

    for index in range(0, size+1):
        if arr[index] > arr[num] :
            num = index
    
    return num

def flipArr(arr, index):
    
    begin = 0
    
    while begin < index :
        temp = arr[begin]
        arr[begin] = arr[index]
        arr[index] = temp
        begin = begin + 1
        index = index - 1


def pancakeSort(arr, size):

    for index in range(size-1, 0 ,-1):
        
        index1 = maxNum(arr, index)

        if index1 != index :
            flipArr(arr, index1)

            flipArr(arr, index)


def main():
    arr = [56, 47, 9, 46, 70, 9, 25, 36]

    size = len(arr)
    
    print("Unsorted Array: ", arr)

    pancakeSort(arr, size)

    print("Sorted Array: ", arr)

if __name__ == "__main__":
    main()