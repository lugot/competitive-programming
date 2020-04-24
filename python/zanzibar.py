for x in range(int(input())):
	data=input().split()
	data=list(map(int,data))
	import_turtles=0
	
	for x in range(1,len(data)-1):
		if data[x] > 2*data[x-1]:
			import_turtles += data[x] - 2*data[x-1]
	
	print(import_turtles)
