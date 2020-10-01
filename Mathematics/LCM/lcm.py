def gcd(a, b):

    if a % b == 0:
        return b
    return gcd(b, a % b)


def lcm(a, b):
    return min(a, b)*gcd(a, b)


print(lcm(6, 9))
