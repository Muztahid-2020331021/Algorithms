#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;

int par[N];
int size[N];

void make(int v){
    par[v]=v;
    size[v]=1;
}

int find(int v){
    if(par[v]==v) return v;
    //*path compresion
    return par[v]=find(par[v]);
}

void euneon(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b])
            swap(a,b);
        par[b]=a;
        size[a]+=size[b];
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(k--){
        int u,v;
        cin>>u>>v;
        euneon(u,v);
    }

    int connected_cc=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) connected_cc++;
    }
}