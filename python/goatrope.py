from math import sqrt

n=input().split()
n=list(map(int, n))

gx,gy = n[0],n[1]

n[0]=n[2]
n[1]=n[5]
n.append(n[4])
n.append(n[3])

if n[2] < gx and gx < n[4]:
	n.append(gx)
	n.append(n[3])
	n.append(gx)
	n.append(n[5])
	
if n[3] < gy and gy < n[5]:
	n.append(n[2])
	n.append(gy)
	n.append(n[4])
	n.append(gy)

min=sqrt( (gx-n[0])**2 + (gy-n[1])**2 )
for x in range(2,len(n),2):
	if sqrt( (gx-n[x])**2 + (gy-n[x+1])**2 ) < min:
		min = sqrt( (gx-n[x])**2 + (gy-n[x+1])**2 )

print(min)
