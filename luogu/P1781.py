n = int(input())
ls = [(i+1, int(input())) for i in range(n)]
ls.sort(key=lambda x: x[1])
print(ls[-1][0])
print(ls[-1][1])
