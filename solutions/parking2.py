from math import ceil,floor

t = int(input())

for x in range(t):
	n = int(input())

	l=input().split()
	l = list(map(int, l))
	avg = sum(l)/n
	
	if max(l)-avg < avg-min(l): avg = floor(avg)
	else: avg = ceil(avg)
	
	print( (avg-min(l))*2 + (max(l)-avg)*2 )
