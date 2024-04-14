
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long dp[20][180][2];

ll digitSum(string &s, ll idx = 0, ll sum = 0, ll tight = 1)
{

    if (idx == s.size())
        return sum;

    if (dp[idx][sum][tight] != -1 and tight != 1)
        return dp[idx][sum][tight];

    ll ret = 0;

    ll k = (tight) ? s[idx]-'0' : 9;

    for (ll i = 0; i <= k; i++)
    {

        ll newTight = ((s[idx]-'0') == i) ? tight : 0;
        ret += digitSum(s, idx + 1, sum + i, newTight);
    }

    if (!tight)
        dp[idx][sum][tight] = ret;

    return ret;
}

ll rangeDigitSum(ll a, ll b)
{

    memset(dp, -1, sizeof(dp));
    string s=to_string(a-1);
    ll ans1 = digitSum(s);

    memset(dp, -1, sizeof(dp));
    s=to_string(b);
    ll ans2 = digitSum(s);

    return (ans2 - ans1);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << "digit sum for given range : " << rangeDigitSum(a, b) << endl;
    return 0;
}
