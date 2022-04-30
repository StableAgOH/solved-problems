n = int(input())
ls = []
for i in range(n):
    s = input()
    ls.append(s.split(' - '))
ls.sort()
le = "00:00:00"
for b,e in ls:
    if b != le:
        print(f"{le} - {b}")
    le = e
if le != "23:59:59":
    print(f"{le} - 23:59:59")
