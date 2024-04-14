#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int par[N];
int size[N];

void make(int v){
    par[v]=v;
    size[v]=1;
}

int find(int v){
    if(par[v]==v) return v;
    return par[v]= find(par[v]);
}

void eunon(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]< size[b])
            swap(a,b);
        par[b]=a;
        size[a]+=size[b];
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int ,int>>>  edges;
    int i;
    for(i=0;i<m ;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(),edges.end());

    for(i=1;i<=n;i++){
        make(i);
    }

    int total_cost=0;
    for(auto &edge : edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        if(find(u)== find(v)) continue;
        eunon(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<"total_cost : "<<total_cost<<endl;


}
/* 
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7

 */