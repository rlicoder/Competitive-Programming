#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int main()
{
    long long n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n,0));
    dp[0][0] = (a[0][0] == '*' ? 0 : 1);
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if (a[i][j] == '*')
            {
                continue;
            }
            long long hi = 0;
            if (i-1 >= 0 && a[i-1][j] != '*')
            {
                hi += dp[i-1][j];
            }
            if (j-1 >= 0 && a[i][j-1] != '*')
            {
                hi += dp[i][j-1];
            }
            dp[i][j] = ((dp[i][j]%mod) + (hi%mod)) % mod;
        }
    }
    cout << dp[n-1][n-1];
}
