#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<bitset<50000>> a(n);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        bitset<50000> z(0);
        z[y] = 1;
        a[x] |= z;
    }
    vector<bool> constructed(n, false);
    function<void(int)> construct = [&] (int i)
    {
        for (auto it : adj[i])
        {
            if (!constructed[it])
            {
                construct(it);
            }
            a[i] |= a[it];
        }
        constructed[i] = true;
    };
    for (int i = 0; i < n; i++)
    {
        if (!constructed[i])
            construct(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].count()+1 << " ";
    }
}
