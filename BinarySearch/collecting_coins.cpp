int solve(vector<vector<int>>& a) 
{
    int n = a.size();
    int m = a[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m,0));
    dp[0][0] = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int high = 0;
            if (i - 1 >= 0)
            {
                high = max(high, dp[i-1][j] + a[i][j]);
            }
            if (j-1 >= 0)
            {
                high = max(high, dp[i][j-1] + a[i][j]);
            }
            dp[i][j] = max(high, dp[i][j]);
        }
    }
    return dp[n-1][m-1];
}
