def pos(a):
	ans = 0
	n = length(ans)
	for i in range(length(a)):
		if a[n-i-1] == '1':
			ans = 2**(i+1)-1-ans

	return ans

n = int(input())
a, b = tuple(map(int, input().split()))


