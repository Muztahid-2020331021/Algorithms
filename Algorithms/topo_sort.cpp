#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj_list(n+1);
	vector<int> indeg(n+1,0);
	for(int i =0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj_list[u].push_back(v);
		indeg[v]++;
	}

	queue<int> pq;
	for(int i = 0; i<n; i++){
		if(indeg[i]==0){
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int x = pq.front();
		pq.pop();
		cout<<x<<" ";
		for(auto it: adj_list[x]){
			indeg[it]--;
			if(indeg[it]==0){
				pq.push(it);
			}
		}
	}
}