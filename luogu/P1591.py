from math import factorial

ls = []
for i in range(1001):
    ls.append(str(factorial(i)))
t = int(input())
for i in range(t):
    n, a = map(int, input().split())
    print(ls[n].count(str(a)))
