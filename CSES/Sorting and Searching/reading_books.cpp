#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    sort(a.begin(), a.end());
    long long l = 0;
    long long r = n-1;
    long long tl, tr;
    tl = a[l];
    tr = a[r];
    while (l < r)
    {
        long long time = min(tl, tr);
        tl -= time;
        tr -= time;
        if (tl == 0)
        {
            l++;
            tl = a[l];
        }
        if (tr == 0)
        {
            r--;
            tr = a[r];
        }
    }
    if (l > r || r != n-1)
    {
        cout << ans;
    }
    else
    {
        cout << ans + min(tl, tr);
    }
    cout << endl;
}
