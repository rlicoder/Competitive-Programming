#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }
    vector<vector<int>> dp(3, vector<int>(n, -2e9));
    dp[0][0] = a[0];
    dp[1][0] = b[0];
    dp[2][0] = c[0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[1][i-1] + a[i], dp[2][i-1] + a[i]);
        dp[1][i] = max(dp[0][i-1] + b[i], dp[2][i-1] + b[i]);
        dp[2][i] = max(dp[0][i-1] + c[i], dp[1][i-1] + c[i]);
    }
    //cout << endl;
    //for (int i = 0; i < n; i++)
    //{
    //    cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << endl;
    //}
    //cout << endl;
    cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
}

