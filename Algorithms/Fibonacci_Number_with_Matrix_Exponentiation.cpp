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

ll T[3][3],I[3][3];

void multi(ll A[][3], ll B[][3]){
    ll i,j,k;
    ll r[3][3];
    REI(i,1,2){
        REI(j,1,2){
            r[i][j]=0;
            REI(k,1,2){
                r[i][j]+=(A[i][k]*B[k][j]);
            }
        }
    }

    REI(i,1,2){
        REI(j,1,2){
            A[i][j]=r[i][j];
        }
    }
}

ll power(ll a, ll b, ll p){
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;

    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;

    p--;
    while(p){
        if(p&1){
            multi(I,T);
        }
        multi(T,T);
        p>>=1;
    }
    ll res=a*I[1][2]+b*I[2][2];
    return res;
}


int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    int i;
    for(i=1;i<=n;i++){
        cout<<"The "<<i<<"-th Fibonacci number is "<<power(a,b,i)<<endl;
    }
    
    
}