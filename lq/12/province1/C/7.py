from time import gmtime, strftime


print(strftime("%H:%M:%S", gmtime(int(input()) // 1000)))
