#include <bits/stdc++.h>

using namespace std;

const int mx = 5;

int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    vector<bitset<mx>> a(n);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        a[i] |= 1<<i;
    }
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        bitset<mx> z;
        z[y] = 1;
        a[x] |= z;
    }
    vector<bool> constructed(n, false);
    function<void(int)> construct = [&] (int i)
    {
        for (int it : adj[i])
        {
            if (it == i) continue;
            if (!constructed[it])
            {
                construct(it);
            }
            a[i] |= a[it];
        }
    };
    for (int i = 0; i < n; i++)
    {
        if (!constructed[i])
        {
            constructed[i] = true;
            construct(i);
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x,y;
        cin >> x >> y;
        if (x == y)
        {
            cout << "YES" << endl;
            continue;
        }
        x--;y--;
        if (a[x][y] == 1)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}
