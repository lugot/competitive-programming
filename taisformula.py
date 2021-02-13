N = int(input())
line = list(map(float, input().split()))

prev_time = line[0]
prev_glu_val = line[1]

gl = 0
for x in range(N-1):
	line = list(map(float, input().split()))
	next_time = line[0]
	next_glu_val = line[1]
	
	gl += (next_time-prev_time)*min(next_glu_val,prev_glu_val)
	gl += (next_time-prev_time)*(max(next_glu_val,prev_glu_val)-min(next_glu_val,prev_glu_val))/2
	
	prev_time = next_time
	prev_glu_val = next_glu_val
	
print(gl/1000)
