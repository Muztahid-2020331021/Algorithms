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
const ll N = 60;
ll I[N][N],arr[N][N];

void multi(ll A[][N],ll B[][N], ll n){
    ll res[n+1][n+1];
    ll i,j;
    REI(i,1,n){
        REI(j,1,n){
            res[i][j]=0;
            for(ll k=1; k<=n; k++){
                res[i][j]=(res[i][j]%mod+((A[i][k]%mod*B[k][j]%mod)%mod)%mod);
            }
        }
    }

    REI(i,1,n){
        REI(j,1,n){
            A[i][j]=res[i][j];
        }
    }
}

void power(ll A[][N],ll n, ll p){
    ll i,j;
    REI(i,1,n){
        REI(j,1,n){
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
        }
    }

    while (p>0)
    {
        if(p%2!=0){
            multi(I,A,n);
        }
        p>>=1;
        multi(A,A,n);
    }

    REI(i,1,n){
        REI(j,1,n){
            A[i][j]=I[i][j]%mod;
        }
    }
    
}


void solve(){
    ll n,m;
    cin>>n>>m;
    ll i,j;
    REI(i,1,n){
        REI(j,1,n){
            cin>>arr[i][j];
        }
    }
    power(arr,n,m);

    REI(i,1,n){
        REI(j,1,n){
            cout<<arr[i][j]%mod<<" ";
        }
        cout<<endl;
    }


}


int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
        
    
}