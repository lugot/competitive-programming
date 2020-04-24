#include <bits/stdc++.h>

/* String Hashing - polynomial way
 *
 * hash(s) = (s[0]*A^(n-1) + s[1]*A^(n-2) + ... + s[n-1]*A^0) mod B
 *  h[k] -> hash value del prefisso s_k
 *  p[k] -> A^k mod B
 *
 *  hash della sottostringa s[a..b] = (h[b] - h[a-1]*p[b-a+1]) mod B
 */

typedef long long ll;
using namespace std;

int main() {
	string pattern,text;

	while(getline(cin,pattern)){
		getline(cin,text);
		int n = text.length();
		int m = pattern.length();

		int failure_function[m+1];
		bzero(failure_function, (m+1)*sizeof(int));
			
		int i=1, j=0;
		while(i<m){
			if (pattern[j] == pattern[i]){
				failure_function[i]=j+1;
				i++;
				j++;
			} else {
				if (j>0) j = failure_function[j-1];
				else {
					failure_function[i]=0;
					i++;
				}
			}
		}

		i=0; j=0;
		while(i<n){
			if (pattern[j]==text[i]) i++, j++;
			if (j==m){
				printf("%d ",i-j);
				j = failure_function[j-1];
			} else if (i<n && pattern[j]!=text[i]){
				if (j>0) j=failure_function[j-1];
				else i++;
			}
		}
		printf("\n");
	}


	return 0;

}
