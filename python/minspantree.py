import numpy as np

def find(x,link):
	while x!= link[x]: x=link[x]
	return x

def same(a,b,link):
	return True if find(a,link) == find(b,link) else False

def unite(a,b,link,same):
	a = find(a,link)
	b = find(b,link)
	
	if size[a] < size[b]: a,b = b,a
	size[a] += size[b]
	link[b] = a


while True:
	input_line = tuple(map(int, input().split()))
	
	n=input_line[0]
	m=input_line[1]
	if n == m == 0:
		break
	
	min_weight=20000
	h = np.array([])
	
	min_span_tree = np.array([])
	weight_sum=0
	nodes_covered=[0 for x in range(n)]
	
	link = [x for x in range(n)]
	size = [1 for x in range(n)]
	
	for x in range(m):
		u,v,w = tuple(map(int, input().split()))
		
		min_weight = min(min_weight,w)
		if u>v: u,v = v,u
		h = np.append(h,(w,u,v))
		
	if min_weight <0:
		for x in range(len(h)):
			h[x] = ( h[x][0]-min_weight ,h[x][1],h[x][2])
	
	h = np.sort(h)
	
	for h_index in range(h.shape[0]):
		print(h[h_index])
		w,a,b = h[h_index]
		if not same(a,b,link):
			weight_sum += w
			unite(a,b,link,same)
			
			nodes_covered[a]=1
			nodes_covered[b]=1
			min_span_tree = np.append(min_span_tree,(a,b))
			
	print(min_span_tree)
	
	for x in nodes_covered:
		if x == 0:
			print("Impossible")
			break
	else:
		if min(nodes_covered) != 0:
			if min_weight < 0:
				weight_sum = weight_sum + min_weight*len(min_span_tree)
			
			print(weight_sum)
			for edge in min_span_tree: print(edge[0],edge[1])
	
