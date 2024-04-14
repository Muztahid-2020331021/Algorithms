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

int d,x,y;

void extenedEuclid(int A, int B){
    if(B==0){
        d=A;
        x=1;
        y=0;
    }
    else{
        extenedEuclid(B,A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int modularInverse(int A, int M){
    extenedEuclid(A,M);
    return (x%M+M)%M;
}

void solve(){
    int a,b;
    cin>>a>>b;
    extenedEuclid(a,b);
    cout<<"The gcd is "<<d<<endl;
    cout<<"The coefficients x and y are "<<x<<" and "<<y<<endl;
    if(d == 1){
        cout<<"The Modular Multiplicative Inverse is "<<modularInverse(a,b)<<endl;
    }

}


int main()
{
    solve();
    
}