from sys import stdin
lines = stdin.readlines()

for line in lines:
    res = eval(line)
    print('{:.2f}'.format(res))
