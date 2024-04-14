#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    vector<ll> profit={20,10,50,15,5}, dead={3,1,2,2,2};
    priority_queue<pair<ll,ll>>pq;
    for(ll i=0; i<profit.size(); i++)
    {
        pq.push({profit[i],dead[i]});
    }
    ll ans=0;
    vector<bool>taken(100,false);
    while(pq.size())
    {
        auto it=pq.top();
        pq.pop();
        if(taken[it.second])continue;
        taken[it.second]=true;
        ans+=it.first;
    }
    cout<<ans<<endl;
}