#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    stack<pair<int,int>> s;
    vector<bool> vis (n+1, false);
    s.push({1,0});
    pair<int,int> hi = {1,0};
    while (!s.empty())
    {
        int cur = s.top().first;
        int dep = s.top().second;
        if (dep > hi.second)
        {
            hi = {cur, dep};
        }
        vis[cur] = true;
        s.pop();
        for (auto it : adj[cur])
        {
            if (!vis[it])
                s.push({it, dep+1});
        }
    }
    s.push({hi.first, 0});
    vis = vector<bool> (n+1, false);
    int ans = 0;
    while (!s.empty())
    {
        int cur = s.top().first;
        int dep = s.top().second;
        vis[cur] = true;
        s.pop();
        for (auto it : adj[cur])
        {
            if (!vis[it])
                s.push({it, dep+1});
        }
        ans = max(ans, dep);
    }
    cout << ans << endl;
}
