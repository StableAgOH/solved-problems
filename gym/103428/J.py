import math


t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    k = a//math.gcd(180*b, a)
    print(180*k*b//a-1)
