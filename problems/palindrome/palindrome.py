def is_palindrome(s):
    s = str(s)
    rev = s[::-1]
    if s == rev:
        return True
    return False


if __name__ == '__main__':
    inputs = ['orange', 'minim',  12321]
    for i in inputs:
        print(f'{i} is a palindrome:{is_palindrome(i)}')
