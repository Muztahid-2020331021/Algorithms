
//* Time complexity is O(V + E*log(V))
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;


vector<pair<int,int>> g[N];

void dijkstra(int source){
    vector<int> vis(N,0);
    vector<int> dist(N,INT_MAX);
    
    set<pair<int,int>> st;
    st.insert({0,source});

    while(st.size()>0){
        auto node= *st.begin();
        int v=node.second;
        int dist_v=node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto child: g[v]){
            int child_v=child.first;
            int wt=child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }

}