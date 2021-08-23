#include <bits/stdc++.h>
 
using namespace std;
 
struct edge
{
    long long a,b,c;
};
 
int main()
{
    #define int long long
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    vector<bool> fromone(n+1, false);
    vector<bool> fromn = fromone;
    vector<vector<int>> adj(n+1, vector<int>());
    vector<vector<int>> rev(n+1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back(y);
        rev[y].push_back(x);
        edge w = {x,y,z};
        e.push_back(w);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        fromone[cur] = true;
        for (auto it : adj[cur])
        {
            if (!fromone[it])
            {
                q.push(it);
            }
        }
    }
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        fromn[cur] = true;
        q.pop();
        for (auto it : rev[cur])
        {
            if (!fromn[it])
            {
                q.push(it);
            }
        }
    }
    vector<int> d(n+1, -2e18);
    d[1] = 0;
    vector<int> tocheck;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[e[j].a] > -2e18)
            {
                d[e[j].b] = max(d[e[j].b], d[e[j].a] + e[j].c);
            }
        }
    }
    bool negative_cycle = false; 
    for (int j = 0; j < m; j++)
    {
        if (d[e[j].a] > -2e18)
        {
            if (d[e[j].a] + e[j].c > d[e[j].b])
            {
                if (fromone[e[j].b])
                {
                    negative_cycle = true;
                }
            }
        }
    }
    if (negative_cycle)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d[n];
    }
}
