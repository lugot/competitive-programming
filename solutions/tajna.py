s = input()
N = len(s)

rc = [(R, C) for R in range(1, N+1) for C in range(1, N+1)
      if R*C == N and R <= C]
rc.sort()
R, C = rc[-1]

for r in range(R):
    i = r
    for _ in range(C):
        print(s[i], end='')
        i += R

print()
