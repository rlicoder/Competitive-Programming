#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 2; i < n-1+2; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    vector<int> dp(n+1, -1);
    function<int(int)> solve = [&] (int i)
    {
        int sum = 1;
        for (auto it : adj[i])
        {
            if (dp[it] == -1)
            {
                dp[it] = solve(it);
            }
            sum += dp[it];
        }
        return sum;
    };
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == -1)
        {
            dp[i] = solve(i);
        }
        cout << dp[i]-1 << " ";
    }
    cout << endl;
}
