N = int(input())
M = int(input())
entry = list(map(int, input().split()))
exit = list(map(int, input().split()))

ct = {}

for x in entry:
	for y in exit:
		if x>y: continue
		if y-x in ct:
			ct[y-x]+=1
		else:
			ct[y-x]=1

max_corr = float('-inf')
for x in ct:
	max_corr = max(max_corr,ct[x])

min_ct = float('inf')
for x in ct:
	if ct[x] != max_corr: continue
	min_ct = min(min_ct,x)

print(ct)
print(min_ct)
