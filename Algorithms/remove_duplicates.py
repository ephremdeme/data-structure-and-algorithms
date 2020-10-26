def remove_duplicates(items):
    unique_items = []
    for i in items:
        if i not in unique_items:
            unique_items.append(i)
    return unique_items


if __name__ == '__main__':
    items = [3, 1, 1, 1, 3, 2, 2, 7, 3, 4, 5, 7, 5, 6, 7, 8, 9, 10]
    expected = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    unique_items = sorted(remove_duplicates(items))

    assert expected == unique_items
