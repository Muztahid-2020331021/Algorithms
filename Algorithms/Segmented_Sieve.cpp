#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define RNI(x,y,n) for(ll x =(ll)(y); x<((ll)n); ++x)
#define REI(x,y,n) for(ll x =(ll)(y); x<=((ll)n); ++x)
#define RND(x,y,n) for(ll x =(ll)(y); x>((ll)n); --x)
#define RED(x,y,n) for(ll x =(ll)(y); x>=((ll)n); --x)
#define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sq(x)   (x)*(x)
#define PI      acos(-1.0)
#define all(x) x.begin(),x.end()
#define endl  "\n"
const ll mod = 1000000007;

vector<int> v;

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.push_back(p);
}

void Segmented_Sieve(int l, int r){
    if(l==1) l++;
    int sze=r-l+1;
    vector<bool> ans(sze,true);
    for(auto p: v){
        if(p*p<=r){
            int i=(l/p)*p;
            if(i<l) i+=p;
            while(i<=r){
                if(i!=p)
                    ans[i-l]=false;
                i+=p;
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i]){
            cout<<i+l<<endl;
        }
    }
}


void solve(){
    int l,r;
    cin>>l>>r;
    Segmented_Sieve(l,r);
    cout<<endl;

}


int main()
{
    SieveOfEratosthenes(100000);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
        
    
}