n = int(input())
cnt = 0


def dfs(s):
    global n, cnt
    if int(s) > n:
        return
    print(f"{s}.mp4")
    cnt += 1
    if cnt == 50:
        exit(0)
    for i in range(10):
        dfs(s+str(i))


for i in range(1, 10):
    dfs(str(i))
