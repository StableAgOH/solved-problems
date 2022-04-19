n = int(input())
a = 0
for i in range(1, n+1):
    s = 1
    for j in range(1, i+1):
        s *= j
    a += s
print(a)
