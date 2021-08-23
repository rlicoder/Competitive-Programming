#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> in(n+1, 0);
    vector<long long> out(n+1, 0);
    vector<vector<long long>> adj(n+1, vector<long long>());
    for (long long i = 0; i < m; i++)
    {
        long long x, y;
        cin >> x >> y;
        in[y]++;
        out[x]++;
        adj[y].push_back(x);
    }
    long long ans = 0;
    const long long MOD = 1e9 + 7;
    vector<long long> dp(n+1, -1);
    function<long long(long long)> dfs = [&] (long long x)
    {
        if (x == 1)
        {
            return 1LL;
        }
        if (dp[x] != -1)
        {
            return dp[x];
        }
        long long ans = 0;
        for (auto it : adj[x])
        {
            ans += dfs(it);
            ans %= MOD;
        }
        dp[x] = ans;
        return ans;
    };
    for (auto it : adj[n])
    {
        ans += dfs(it);
        ans %= MOD;
    }
    cout << ans << endl;
}
