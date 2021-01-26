#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> low(n);
    for (int i = 0; i < n; i++)
    {
        int lo = 1e9;
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            lo = min(lo, a[i][j]);
        }
        low[i] = lo;
    }
    cout << *max_element(low.begin(), low.end()) << endl;
}
