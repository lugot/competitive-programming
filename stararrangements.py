from math import ceil,floor

def main():
	n=int(input())
	print("%d:"%n)
	
	for x in range(2,ceil(n/2)+1):
		first=x
		second=x-1
		
		if flag_possible(n,first,second): print(f'{first},{second}')
		second+=1
		if flag_possible(n,first,second): print(f'{first},{second}')
		
def flag_possible(n, first, second):
	if (n-first)%(first+second)==0 or n%(first+second)==0: return True
	return False
	
main()
