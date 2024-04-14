#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e2;

ll FastModExp(ll a, ll b)
{
    ll res=1;
    while(b>0){
        if(b&1){
            res=((res%N)*(a%N))%N;
        }
        a=(a%N)*(a%N);
        b>>=1;
    }
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout<<FastModExp(a,b)<<endl;
}