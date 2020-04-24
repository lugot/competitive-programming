from math import floor

def main():
	n=int(input())
	
	set_number=1
	while(n!=0):
		print(f'SET {set_number}')
		set_number+=1
		L=[]
		for x in range(0,int(n/2)):
			print(input())
			L.append(input())
		if n%2!=0: print(input())
		
		while(len(L)!=0):
			print(L.pop())
		
		n=int(input())
		
main()
