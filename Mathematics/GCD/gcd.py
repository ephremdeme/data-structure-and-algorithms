def gcd(a,b = None):
    if b != None:
        if a % b == 0:
            return b
        else:
            return gcd( b, a % b)
    else:
        for i in range(len(a)):
            a[0] = gcd(a[0],a[i])
        return a[0]



print(gcd([18,12, 6]))

print(gcd(9, 12))