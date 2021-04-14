#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    int cur = 0;
    cur = max(a[0].first, a[0].second);
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        if (cur < a[i].first && cur < a[i].second)
        {
            ok = false;
        }
        if (max(a[i].first, a[i].second) > cur)
        {
            cur = min(a[i].first, a[i].second);
        } 
        else
        {
            cur = max(a[i].first, a[i].second);
        }
    }
    cout << (ok ? "YES" : "NO") << endl;

}
