l = input().split()
l = list(map(int, l))

N = l[0]
M = l[1]

move=0
while N>0 and M>0:
	MIN = min(N,M)
	MAX = max(N,M)
	
	if MAX % MIN == 0 or MAX > MIN*2:
		MAX = 0
		N = MAX
		M = MIN
	else:
		if MAX//MIN > 2:
			MAX -= MIN*(MAX//MIN-1)
		else:
			MAX -= MIN
		M = MAX
		N = MIN
	
	#print(MAX," ",MIN)
	
	move+=1

print( "win" if move%2!=0 else "lose" )
