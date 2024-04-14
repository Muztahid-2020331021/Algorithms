#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
int cnt=0;

void add(int v){
    if(mp[v]==0) cnt++;
    mp[v]++;
}

void remove(int v){
    mp[v]--;
    if(mp[v]==0) cnt--;
}
 
int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k,d;
        cin>>n>>k>>d;

        mp.clear();
        cnt=0;

        int x[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }

        for(int i =0; i<d; i++){
            add(x[i]);
        }

        int ans = cnt;
        for(int i=d;i<n;i++){
            add(x[i]);
            remove(x[i-d]);

            ans=min(ans,cnt);
        }
        cout<<ans<<endl; 
    }
}