for x in range(int(input())):
	n = int(input())
	cities = []
	
	for y in range(n):
		cities.append(input())
		
	print(len(set(cities)))
