#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int x[n+1];
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    int pref[n+2], suff[n+2];

    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i]=__gcd(pref[i-1],x[i]);
    }

    suff[n+1]=0;
    for(int i=n;i>=1;i--){
        suff[i]=__gcd(suff[i+1],x[i]);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,__gcd(pref[i-1],suff[i+1]));
    }
    cout<<ans<<endl;
}