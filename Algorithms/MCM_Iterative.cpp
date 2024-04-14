#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int arr[], int n)
{
    int dp[n][n];

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << MatrixChainOrder(arr, size) << endl;
}