#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<pair<ll,ll>>interval={{11,9},{13,10},{15,14},{18,16},{14,12},{18,15},{16,13},{13,11}};// first element of pair will store ending time and second will store starting time
    ll numberOfClass=0, prev_end=0;
    sort(interval.begin(), interval.end());//sort in increasing order according to finishing time
    for(ll i=0; i<interval.size(); i++)
    {
        ll en=interval[i].first, st=interval[i].second;
        if(st<prev_end)continue;
        /* |-----|
              |--------|
        */

        numberOfClass++;
        prev_end=en;
    }
    cout<<numberOfClass<<endl;
}