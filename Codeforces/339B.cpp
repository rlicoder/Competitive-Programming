#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    int cur = 1;
    for (int i = 0; i < m; i++)
    {
        if (a[i]-cur < 0)
        {
            ans += a[i] + abs(cur-n);
            cur = a[i];
        }
        else
        {
            ans += abs(a[i]-cur);
            cur = a[i];
        }
    }
    cout << ans << endl;
}
