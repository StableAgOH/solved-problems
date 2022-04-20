from math import log10, floor


def qpow(a, k, p):
    res = 1
    while k:
        if k & 1:
            res = res*a % p
        a = a*a % p
        k >>= 1
    return res


n = int(input())
print(floor(log10(2)*n+1))
s = str(qpow(2, n, 10**500)-1)
if len(s) < 500:
    s = '0'*(500-len(s))+s
for i in range(10):
    print(s[i*50:(i+1)*50])
