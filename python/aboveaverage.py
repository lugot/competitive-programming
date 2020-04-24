def avg(l):
	t=0
	for x in l: t+=x
	
	return t/len(l)


C = int(input())

for x in range(C):
	i = list(map(int, input().split()))

	average = avg(i[1:])
	count = 0
	for y in i[1:]:
		if y > average: count+=1
	count = count/i[0]*100
	
	print("{0:.3f}%".format(count))
