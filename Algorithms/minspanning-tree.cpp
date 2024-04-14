#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
struct Edge{
    ll u,v,w;
    bool operator<(Edge const& other)
    {
        return w<other.w;
    }
};
ll parent[N];
ll find_parent(ll v)
{
    if(parent[v]==v)return v;
    return parent[v]=find_parent(parent[v]);
}
void Union(ll u, ll v)
{
    ll par_u=find_parent(u), par_v=find_parent(v);
    if(par_u==par_v)return;
    parent[par_v]=par_u;
}
int main()
{
    vector<Edge>graph;
    ll e;
    cin>>e;
    for(ll i=0; i<e; i++)
    {
        Edge e;
        cin>>e.u>>e.v>>e.w;
        graph.push_back(e);
    }
    for(ll i=0; i<N; i++)parent[i]=i;
    sort(graph.begin(), graph.end());
    vector<Edge>ans;
    for(auto &it: graph)
    {
        ll u=it.u, v=it.v, w=it.w;
        if(find_parent(u)==find_parent(v))continue;
        ans.push_back(it);
        Union(u,v);
    }
    for(auto &it: ans)cout<<it.u<<" "<<it.v<<" "<<it.w<<endl;
}