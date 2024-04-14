#include <bits/stdc++.h>
using namespace std;
#define ll long long


int SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    int cnt=0;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cnt++;
    return cnt;
}


int main()
{
    int t;
    cin>>t;
    while(cin>>t){
        if(t==0){
            break;
        }
        double x=SieveOfEratosthenes(t);
        double y= x/log(x);
        double p=abs(x-y);
        double ans = p/x;
        cout<<fixed<<setprecision(1)<<ans*100<<endl;

    }
        
    
}