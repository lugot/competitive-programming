#include <bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
	cin >> N >> M;

	vector<int> nodes[N+1];
	int a,b;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	char visited[N+1];
	bzero(visited,N+1);
	
	int current;
	queue<int> q;
	visited[1]=1;
	q.push(1);
	while(!q.empty()){
		current = q.front();
		q.pop();
		
		for(int x : nodes[current]){
			if (!visited[x]){
				visited[x]=1;
				q.push(x);
			}
		}
	}
	
	int flag=0;
	for(int i=1; i<N+1; i++) 
		if (!visited[i]){
			flag=1;
			printf("%d\n",i);
		}
	
	if (!flag) printf("Connected\n");
	return 0;
}
