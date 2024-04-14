#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mx=-1;
ll room[10][10];
int main()
{
    ll dead[]={10,15,10,15,13,13,15,13,15}; 
    ll dur[] ={1,1,1,1,1,3,3,3,3};
    vector<pair<ll,ll>>v;
    for(ll i=0; i<9; i++)
    {
       ll end_time=dead[i], start_time=end_time-dur[i];
       if(end_time>13 and start_time<13)//break handleing
       {
        end_time=13;
        start_time=13-dur[i];
       }
       v.push_back({end_time,0});
       v.push_back({start_time,1}); 
    }
    sort(v.begin(), v.end());
    ll numberOfRooms=0, ans=INT_MIN;
    for(ll i=0; i<9; i++)
    {
        if(v[i].second)numberOfRooms++;
        else numberOfRooms--;

        ans=max(ans, numberOfRooms);
    }
    cout<<ans<<endl;
}