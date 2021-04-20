#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i+1];
    }
    vector<vector<int>> adj(n+1, vector<int>());
    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis (n+1, false);
    set<int> s;
    queue<pair<int, string>> q;
    q.push({1,""});
    set<int> ans;
    while (!q.empty())
    {
        pair<int,string> cur = q.front();
        q.pop();
        vis[cur.first] = true;
        if (!s.count(cur.first))
        {
            //shortest path
            s.insert(cur.first);
            bool valid = true;
            for (char x : cur.second)
            {
                //not valid
                if (c[x -'0'] == c[cur.first])
                {
                    valid = false;
                }
            }
            if (valid)
            {
                ans.insert(cur.first);
            }
        }
        for (auto it : adj[cur.first])
        {
            if (!vis[it])
            {
                string path = cur.second;
                path += cur.first + '0';
                q.push({it, path});
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << endl;
    }
}
