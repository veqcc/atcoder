mod = 1000000007

def mul(a, b):
    return ((a % mod) * (b % mod)) % mod

def power(x, y):
    if   y == 0     : return 1
    elif y == 1     : return x % mod
    elif y % 2 == 0 : return power(x, y/2)**2 % mod
    else            : return power(x, (y-1)/2)**2 * x % mod

def div(a, b):
    return mul(a, power(b, mod-2))


print(power(2, mod-2))