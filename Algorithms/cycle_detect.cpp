#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;

vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par){
    
    vis[vertex]=true;
    bool ifloopexist=false;
    for(auto child: g[vertex]){
        if(vis[child]  && child==par) continue;
        if(vis[child]) return true; 
        ifloopexist|=dfs(child, vertex);
    }
    return ifloopexist;
}


int main(){
    int n,e;
    cin>>n>>e;
    int i;
    for(i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool ifloopexist=false;
    for(i=1;i<=n;i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            ifloopexist=true;
            break;
        }
    }
    cout<<ifloopexist<<endl;

}
/* 
8 5
1 2
2 3
2 4
3 5
6 7
 */