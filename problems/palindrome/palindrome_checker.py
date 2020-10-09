def palindrome_checker(string):
    counter = {}
    for i in range(26):
        counter[chr(ord('a') + i)] = 0
        
    for s in string:
        counter[s] += 1

    odd = 0
    for c in counter:
        if counter[c] % 2 != 0:
            if odd == 0:
                odd = 1
            else:
                return False
    return True
