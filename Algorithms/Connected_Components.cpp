#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> cur_cc;

void dfs(int vertex){
    if(vis[vertex]) return;
    vis[vertex]=true;
    cur_cc.push_back(vertex);
    for(auto child: g[vertex]){
        dfs(child);
    }
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
    
    for(i=1;i<=n;i++){
        if(vis[i]) continue;
        cur_cc.clear();
        dfs(i);
        cc.push_back(cur_cc);
    }
    cout<<cc.size()<<endl;
    for(auto c_cc: cc){
        for(auto ver: c_cc){
            cout<<ver<<" ";
        }
        cout<<endl;
    }
}
/* 
8 5
1 2
2 3
2 4
3 5
6 7
 */