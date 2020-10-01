## Implementation of firstDuplicate in Python3
## Example Input : a = [2, 1, 3, 5, 3, 2]
## Example Output: 3


def firstDuplicate(a):
    new_list=set()
    for i in a:
        if i not in new_list:
            new_list.add(i)
        else:
            return i
    return -1   

if __name__=="__main__":
    a = [2, 1, 3, 5, 3, 2]
    print(firstDuplicate(a))