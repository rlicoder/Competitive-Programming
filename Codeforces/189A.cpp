#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, -1e9);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i - a >= 0 && dp[i-a] != -1e9)
        {
            dp[i] = max (dp[i], dp[i-a] + 1);
        }
        if (i - b >= 0 && dp[i-b] != -1e9)
        {
            dp[i] = max (dp[i], dp[i-b] + 1);
        }
        if (i - c >= 0 && dp[i-c] != -1e9)
        {
            dp[i] = max (dp[i], dp[i-c] + 1);
        }
    }
    cout << dp[n] << endl;

}
