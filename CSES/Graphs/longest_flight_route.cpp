#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> in(n+1, 0);
    queue<int> q;
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> dp(n+1, INT_MIN);
    dp[1] = 1;
    q.push(1);
    vector<int> p(n+1);
    p[1] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur])
        {
            if (dp[cur] != INT_MIN && dp[cur] + 1 > dp[it])
            {
                dp[it] = dp[cur] + 1;
                p[it] = cur;
                q.push(it);
            }
            in[it]--;
            if (in[it] == 0)
            {
                q.push(it);
            }
        }
    }
    if (dp[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dp[n] << endl;
    vector<int> path;
    for (int x = n; x != 1; x = p[x])
    {
        path.push_back(x);
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (auto it : path)
    {
        cout << it << " ";
    }
}
