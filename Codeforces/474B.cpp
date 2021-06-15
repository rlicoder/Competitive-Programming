#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> pref(n+1);
    pref[0] = 0;
    for (int i = 0; i < n; i++)
    {
        pref[i+1] = pref[i] + a[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << lower_bound(pref.begin(), pref.end(), x) - pref.begin() << endl;
    }
}
