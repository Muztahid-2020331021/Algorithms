#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<vector<int>> &adj, int s, int d) {
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == d) break; // Stop early if destination is reached

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // Reconstruct the path
    vector<int> path;
    if (!visited[d]) return {}; // No path found

    for (int v = d; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, e, s, d;
    cin >> n >> e >> s >> d;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    vector<int> path = bfs(n, adj, s, d);

    if (path.empty()) {
        cout << "No path found" << endl;
    } else {
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
