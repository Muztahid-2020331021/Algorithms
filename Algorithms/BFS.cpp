#include<bits/stdc++.h>
using namespace std;
const int N=50;
vector<int> g[N];
int vis[N];
int par[N];

// bool bfs(int source, int dest)
// {
//     queue<int> q;
//     q.push(source);
//     vis[source] = 1;
//     par[source] = -1;
//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();

//         for (auto child : g[cur])
//         {
//             if(vis[child]) continue;
//             q.push(child);
//             vis[child] = 1;
//             par[child] = cur;
//             if (child == dest)
//                 return true;
//         }
//     }
//     return false;
// }

void bfs(int source, int dest){
    queue<int> q;
    q.push(source);
    vis[source]=1;
    par[source]=0;
    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        
        for(auto child: g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                par[child]=cur_v;
                if(child==dest) return;
            }
        }
    }
    cout<<"There is no destination!!\n";
    
}

int main(){
    int n;
    cin>>n;
    int i;
    for(i=0;i<13;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    bfs(1,15);
    i=10;
    stack<int> ans;
    while (i!=0)
    {
        ans.push(i);
        i=par[i];
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<endl;
    
    

}
/*
13
1 2
1 3
1 13
1 10
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11
9 11
*/