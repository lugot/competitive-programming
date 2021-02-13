from sys import stdin
from math import factorial as f

lines = stdin.readlines()

for line in lines: #wtf it passed, fact inside python is goooood
    line = line[0:len(line)-1] #\n is included
    
    d = {}
    for c in line:
        if c not in d.keys(): d[c]=0
        d[c]+=1
    
    ans = f(len(line))
    for k in d.keys():
        ans = ans // f(d[k])

    print(ans)

