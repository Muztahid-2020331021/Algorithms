#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define faster  ios_base::sync_with_stdio(0);
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define endl  "\n"
ll mod;
vector<ll> fact(1000050,0);

ll FastModExp(ll a, ll b)
{
    ll res=1;
    while(b>0){
        if(b&1){
            res=((res%mod)*(a%mod))%mod;
        }
        a=(a%mod)*(a%mod);
        b>>=1;
    }
    return res%mod;
}



ll modInv(ll n){
    return FastModExp(n,mod-2)%mod;
}

ll nCr(ll n,ll r){

    return ((fact[n]%mod)*(modInv(fact[n-r])*modInv(fact[r])%mod))%mod;
}

ll lucas(ll n, ll m){
    if(m<0 or m>n){
        return 0;
    }
    if(n==0 and m==0){
        return 1;
    }
    ll ni = n%mod;
    ll mi = m%mod;
    if(mi>ni){
        return 0;
    }
    return lucas(n/mod,m/mod)*nCr(ni,mi)%mod;
}
