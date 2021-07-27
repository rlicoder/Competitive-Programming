#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> dp(n, 2e18);
    dp[0] = 0;
    for (long long i = 1; i < n; i++)
    {
        if (i-1>=0)
        {
            dp[i] = min(dp[i], dp[i-1] + abs(a[i] - a[i-1]));
        }
        if (i-2>=0)
        {
            dp[i] = min(dp[i], dp[i-2] + abs(a[i] - a[i-2]));
        }
    }
    cout << dp[n-1] << endl;
}
