#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Rep_Less(x,y,n) for(ll x =(ll)y; x<(ll)n; ++x)
#define Rep_Equal(x,y,n) for(ll x =(ll)y; x<=(ll)n; ++x)
const int N=101;

int arr[N][N],I[N][N];

void multi(int A[][N], int B[][N], int n){
    int i,j,k;
    int r[n+1][n+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            r[i][j]=0;
            for(k=1;k<=n;k++){
                r[i][j]+=(A[i][k]*B[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            A[i][j]=r[i][j];
        }
    }
}

void power(int A[][N],int n, int p){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j) I[i][j]=1;
            else I[i][j]=0;
        }
    }

    while(p>0){
        if(p%2!=0){
            multi(I,A,n);
        }
        p/=2;
        multi(A,A,n);
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            A[i][j]=I[i][j];
        }
    }
}

int main(){
    int n,p;
    cin>>n>>p;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    power(arr,n,p);
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}