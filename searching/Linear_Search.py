def LinearSearch(a, size, key):
    for i in range(size):
        if a[i] == key :
            return i
    return -1

if __name__ == "__main__":
    a = []
    n = int(input("Enter the number of elements in array :"))
    print("Enter the elements in array :")
    for i in range(n):
        a.append(int(input()))
    print("Array is :", a)
    key = int(input("Enter the element to be searched :"))
    result = LinearSearch(a, n, key)
    if result == -1 :
        print("Element not found")
    else:
        print("Element found at index : {}".format(result))
