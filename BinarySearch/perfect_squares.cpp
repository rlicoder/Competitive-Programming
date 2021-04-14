int solve(int n) {
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int low = 1e9;
        for (int j = 1; j*j <= i; j++)
        {
            dp[i] = min(low, dp[i-(j*j)] + 1);
        }
        dp[i] = min(dp[i], low);
    }
    return dp[n];
}
