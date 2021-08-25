#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> queries;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        queries.push_back(x);
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    
}
