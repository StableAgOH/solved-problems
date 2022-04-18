from re import I


t = int(input())
for _ in range(t):
    x = int(input())
    ls = []
    for i in range(2, 10):
        y = str(x*i)
        s = sum(map(int, y))
        ls.append(s)
    if ls.count(ls[0]) == len(ls):
        print(ls[0])
    else:
        print("NO")
