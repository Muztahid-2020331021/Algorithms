#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll Derangement(ll n){

    vector<ll> d(n+1,0);

    d[0]=1;
    d[1]=0;
    d[2]=1;

    for(int i=3;i<=n;i++){
        d[i]=(i-1)*(d[i-1]+d[i-2]);
    }

    return d[n];
}

int main(){
    ll n;
    cin>>n;
    
    cout<<"Derangement of "<<n<<" is "<<Derangement(n)<<endl;
}