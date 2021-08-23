#include <bits/stdc++.h>

using namespace std;

vector<int> par;
vector<int> sz;

int find(int x)
{
    return (x == par[x] ? x : par[x] = find(par[x]));
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        par[y] = x;
        sz[x] += sz[y];
    }
}



int main()
{
    int n, m;
    cin >> n >> m;
    par.resize(n+1);
    sz.resize(n+1, 1);
    iota(par.begin(), par.end(), 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        unite(x,y);
    }
    set<int> s;
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        int x = find(i);
        if (s.count(x) == 0)
        {
            if (sz[x] >= 3)
            {
                found = true;
            }
            //cout << "parent of: " << i << " is " << x << endl;
            //cout << "sz of: " << i << " is " << size[x] << endl;
        }
    }
    if (found)
    {
        cout << "YES";
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    
}
