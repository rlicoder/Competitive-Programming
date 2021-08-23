#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n+1, false);
    vector<bool> instack(n+1, false);
    vector<int> ans;
    bool cycle = false;
    function<bool(int)> dfs = [&] (int cur)
    {
        visited[cur] = true;
        instack[cur] = true;
        for (auto it : adj[cur])
        {
            if (visited[it] && instack[it])
            {
                return true;
            }
            if (!visited[it])
            {
                if (dfs(it))
                {
                    return true;
                }
            }
        }
        instack[cur] = false;
        ans.push_back(cur);
        return false;
    };
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) 
        {
            cycle |= dfs(i);
        }
    }
    if (ans.size() && !cycle)
    {
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
}
