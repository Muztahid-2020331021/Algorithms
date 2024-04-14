#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define sz 10000/////After Dark
using namespace std;

vector<int> adj[sz];
bool visited[sz];
int parent[sz];

int bfs(int start, int destination, int node_number)
{
	queue<pair<int, int>> q;
	q.push({start, 0});
	visited[start] = 1;
	memset(parent, -1, sizeof(int) * node_number);
	int x, cost;
	while (!q.empty())
	{
		x = q.front().first;
		cost = q.front().second;
		q.pop();
		if(x==destination) return cost;
		for (auto &now : adj[x])
		{
			if (!visited[now])
			{
				visited[now]=1;
				q.push({now,cost+1});
				parent[now]=x;
			}
		}
	}
	return -1;
}

int main(){
	int vertex, edge, start, destination, u, v;
	cin>>vertex>>edge>>start>>destination;
	for(int i=0;i<edge;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int distance=bfs(start,destination,vertex);
	cout<<"Minimum Distance from "<<start<<" to "<<destination<<" is = "<<distance<<"\n";

	int x=destination;
	vector<int> answer;
	while(~x){
		answer.push_back(x);
		x=parent[x];
	}
	reverse(answer.begin(),answer.end());
	cout<<"The shortest path is : ";
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<",\n"[i==answer.size()-1];
	}
}