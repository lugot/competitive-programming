d1,d2,d3,d4 = map(int, input().split())

gunnar=0
t=0
for x in range(d1,d2+1): t+=x
gunnar += t/(d2-d1+1)

t=0
for x in range(d3,d4+1): t+=x
gunnar += t/(d4-d3+1)


d1,d2,d3,d4 = map(int, input().split())

emma=0
t=0
for x in range(d1,d2+1): t+=x
emma += t/(d2-d1+1)

t=0
for x in range(d3,d4+1): t+=x
emma += t/(d4-d3+1)

if emma > gunnar: print("Emma")
elif gunnar > emma: print("Gunnar")
else: print("Tie")
