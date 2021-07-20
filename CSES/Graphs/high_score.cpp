#include <bits/stdc++.h>

using namespace std;


struct edge
{
    int a,b,c;
};

int main()
{
    #define int long long
    int n, m;
    cin >> n >> m;
    vector<edge> adj;
    for (int i = 0; i < m; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        edge w;
        w.a = x;
        w.b = y;
        w.c = z;
        adj.push_back(w);
    }
    vector<int> d (n+1, -2e18);
    d[1] = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[adj[j].a] > -2e18)
            {
                d[adj[j].b] = max(d[adj[j].b], d[adj[j].a] + adj[j].c);
            }
        }
    }
    bool negative_cycle = 0;
    for (int j = 0; j < m; j++)
    {
        if (d[adj[j].a] > -2e18)
        {
            if (d[adj[j].a] + adj[j].c > d[adj[j].b])
            {
                negative_cycle = true;
            }
        }
    }
    if (negative_cycle)
    {
        cout << -1;
    }
    else
    {
        cout << d[n];
    }
    cout << endl;
}
