#include <bits/stdc++.h>

using namespace std;

vector<int> par;
vector<int> sz;

int hi = 0;
int num;

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
        num--;
        if (sz[y] > sz[x])
        {
            swap(x,y);
        }
        par[y] = x;
        sz[x] += sz[y];
        hi = max(hi, sz[x]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    num = n;
    par.resize(n+1);
    iota(par.begin(), par.end(), 0);
    sz.resize(n+1, 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        unite(x,y);
        cout << num << " " << hi << endl;
    }
}
