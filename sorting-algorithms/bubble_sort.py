def bubble_sort(array):
    n = len(array)
    swapped = True
    while swapped:
        swapped = False
        for j in range(n-1):
            if array[j] > array[j + 1]:
                array[j], array[j+1] = array[j+1], array[j]
                swapped = True

    return array


if __name__ == '__main__':
    array = [2, 3, 4, 40, 100, 20, 10, 5, 130]
    print('Unsorted array: {}'.format(array))
    print('Sorted array: {}'.format(bubble_sort(array)))