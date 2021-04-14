int solve(int n) {
    vector<int> dp (n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    const int mod = 1e9+7;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    return dp[n];
}
