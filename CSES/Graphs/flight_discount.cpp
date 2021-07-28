#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int a,b,c;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    vector<int> p(n+1, 1e9);
    p[1] = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[a[j].a] < 1e9)
                p[a[j].b] = min(p[a[j].b], p[a[j].a] + a[j].c);
        }
    }
    for (auto it : p)
    {
        cout << it << " ";
    }
    cout << endl;
}
