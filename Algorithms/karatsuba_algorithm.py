def zero(numberString, zeros, left = True):
    """Return the string with zeros added to the left or right."""
    for i in range(zeros):
        if left:
            numberString = '0' + numberString
        else:
            numberString = numberString + '0'
    return numberString


  def Multiplication(x ,y):
    
    x = str(x)
    y = str(y)
    # recursion base case
    if len(x) == 1 and len(y) == 1:
        return int(x) * int(y)
    if len(x) < len(y):
        x = zero(x, len(y) - len(x))
    elif len(y) < len(x):
        y = zero(y, len(x) - len(y))
    n = len(x)
    j = n//2
    if (n % 2) != 0:
        j += 1    
    BZeroPadding = n - j
    AZeroPadding = BZeroPadding * 2
    a = int(x[:j])
    b = int(x[j:])
    c = int(y[:j])
    d = int(y[j:])
    ac = Multiplication(a, c)
    bd = Multiplication(b, d)
    k = Multiplication(a + b, c + d)
    A = int(zero(str(ac), AZeroPadding, False))
    B = int(zero(str(k - ac - bd), BZeroPadding, False))
    return A + B + bd
