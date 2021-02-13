line = input().split()
line = list(map(int, line))

R = line[0]
C = line[1]
Zr = line[2]
Zc = line[3]

for x in range(R):
	line = input()
	to_print=""
	
	for y in range(C):
		to_print+=line[y]*Zc
		
	for x in range(Zr): 
		print(to_print)
	
