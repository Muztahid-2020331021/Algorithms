#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int MatrixChainMemoised(int *p, int i, int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=1;k<j;k++){
        dp[i][j]=min(dp[i][j],MatrixChainMemoised(p,i,k)+MatrixChainMemoised(p,k+1,j)+p[i-1]*p[k]*p[j]);
    }
    return dp[i][j];
}

int main(){
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
    cout<<MatrixChainMemoised(arr,1,n-1)<<endl;

}