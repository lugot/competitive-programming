def is_harshad(n):
	sum_of_digit=0
	n1=n
	while n!=0:
		sum_of_digit+=n%10
		n//=10
	if n1%sum_of_digit==0: return True
	return False

def next_harshad(n):
	while(not is_harshad(n)):
		n+=1
	return n

def main():
	n = int(input())
	print(next_harshad(n))
	
main()
