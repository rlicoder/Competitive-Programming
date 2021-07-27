#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 1;
    int r = 1;
    int ans = 0;
    vector<int> pref(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i+1] = pref[i] + a[i];
    }
    while (l <= n && r <= n)
    {
        while (pref[r] - pref[l-1] < x)
        {
            r++;
        }
        if (r > n)
        {
            break;
        }
        if (pref[r] - pref[l-1] == x)
        {
            //cout << r << " to " << l << endl;
            ans++;
            l++;r++;
        }
        if (r > n || l > n)
        {
            break;
        }
        while (pref[r] - pref[l-1] > x)
        {
            l++;
        }
        if (l > n)
        {
            break;
        }
        if (pref[r] - pref[l-1] == x)
        {
            //cout << r << " to " << l << endl;
            ans++;
            l++;r++;
        }
    }
    cout << ans << endl;
}
