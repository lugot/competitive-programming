fib_numbers = {}
fib_numbers[1]=1
fib_numbers[0]=0

def fib(n):
	if n==0: return 0
	if n==1: return 1
	if n==2: return 1

	if n%2==0:
		k = n//2
	else:
		k = n-1
		k = k//2

	if k in fib_numbers:
		f_k = fib_numbers[k]
	else:
		f_k = fib(k)
		fib_numbers[k] = f_k

	if k+1 in fib_numbers:
		f_k1 = fib_numbers[k+1]
	else:
		f_k1 = fib(k+1)
		fib_numbers[k+1] = f_k1


	if n%2==0: f_n = f_k*(2*f_k1 - f_k)
	else: f_n = f_k**2 + f_k1**2

	f_n = f_n%1000000000
	return f_n

P = int(input())
for x in range(P):
	K,Y = tuple(map(int,input().split()))
	print(K,fib(Y))
