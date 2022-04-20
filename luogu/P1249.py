n = int(input())
s = 0
m = 1
i = 2
while True:
    s += i
    m *= i
    if s > n:
        break
    i += 1
if s-n == 1:
    m = m//(i-1)*i
    print(*[_ for _ in range(2, i)], i+1)
else:
    m = m//(s-n)
    print(*[_ for _ in range(2, i+1) if _ != s-n])
print(m)
