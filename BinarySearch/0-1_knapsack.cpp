
int solve(vector<int>& w, vector<int>&v, int c)
{
    int n = v.size();

    vector<int>dp(c+1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = c; j >= 0; j--)
        {
            if (j - w[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            }
        }
    }

    // for(int i = 0; i <= c; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    return dp[c];
}

