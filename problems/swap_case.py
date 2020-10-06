def swap_case(s):
    letter = ""
    for i in s:
        if i.isalpha():
            if i.islower():
                j = i.upper()
                letter += j
            else:
                j = i.lower()
                letter += j
        else:
            letter += i

    return letter


s = input("Enter String: ")
print(swap_case(s))