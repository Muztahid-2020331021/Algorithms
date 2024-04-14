#include<bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2, int m, int n){
    int dp[m+1][n+1];

    int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    string LCS;

    i=m,j=n;
    while(i>0 and j>0){
        if(s1[i-1]==s2[j-1]){
            LCS = s1[i-1] + LCS;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]) i--;
        else j--;
    }
    return LCS;
}

int main(){
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();
    string LCS = lcs(S1,S2,m,n);
    cout<<"The LCS is "<<LCS<<endl;
    cout<<"The length is "<<LCS.length()<<endl;
}