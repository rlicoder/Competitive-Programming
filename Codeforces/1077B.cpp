#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a(n, {0,false});
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 1; i < n-1; i++)
    {
        if (a[i].first == 0 && a[i+1].first == 1 && a[i-1].first == 1)
        {
            a[i].second = true;
            i++;
        }
    }
    int ans = 0;
    for (int i = 2; i < n-2; i++)
    {
        if (a[i-1].second && a[i+1].second && a[i].first == 1)
        {
            a[i-1].second = false;
            a[i+1].second = false;
            a[i].first = 0;
            ans++;
        }
    }
    for (int i = 1; i < n-1; i++)
    {
        if (a[i].first == 0 && a[i+1].first == 1 && a[i-1].first == 1)
        {
            a[i].second = true;
            ans++;
        }
    }
    cout << ans << endl;
}
