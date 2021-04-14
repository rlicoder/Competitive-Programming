#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vector<int>p(n+1);
    vector<bool> vis(n+1, false);
    p[1] = 1;
    vis[1] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : a[cur])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = true;
                p[it] = cur;
            }
        }
    }
    if(vis[n])
    {
        int i = n;
        vector<int>ans;
        ans.push_back(i);
        while (i != 1)
        {
            i = p[i];
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
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
