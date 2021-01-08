#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    int ans = 0;
    int i = 0;
    while (n > 0 && i < m)
    {
        if (a[i].second >= n)
        {
            ans += a[i].first * n;
            n = 0;
        }
        else
        {
            ans += a[i].first * a[i].second;
            n -= a[i].second;
        }
        i++;
    }
    cout << ans << endl;
}
