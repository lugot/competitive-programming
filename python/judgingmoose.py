line = input().split()
line = list(map(int, line))

l = line[0]
r = line[1]

if l==0 and r==0:
	print("Not a moose")
elif l==r:
	print("Even ",l*2)
else:
	print("Odd ",max(line)*2)
