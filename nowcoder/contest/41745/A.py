n, m = map(int, input().split())
ls = []
for i in range(n):
    ls.append(input())
for i in range(m):
    flag = False
    s = input()
    for j in ls:
        if j in s:
            print("bieexina")
            flag = True
            break
    if not flag:
        print("enenen")
