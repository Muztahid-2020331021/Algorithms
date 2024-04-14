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

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b,a%b);
}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b)<<endl;

}


int main()
{
    solve();
    
}