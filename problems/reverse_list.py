def reverse_list(items):
    start = 0
    end = len(items) - 1

    while start < end:
        items[start], items[end] = items[end], items[start]
        start += 1
        end -= 1

    return items


if __name__ == '__main__':
    items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(reverse_list(items))
