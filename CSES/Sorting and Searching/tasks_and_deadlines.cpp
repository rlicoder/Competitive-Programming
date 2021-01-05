#include <bits/stdc++.h>

using namespace std;

int main()
{
     unsigned long long n;
    cin >> n;
    vector<pair< unsigned long long, unsigned long long>> a(n);
    for ( unsigned long long i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
     unsigned long long i = 0;
     unsigned long long time = 0;
     long long ans = 0;
    while (i < a.size())
    {
        time += a[i].first;
        ans += a[i].second - time;
        i++;
    }
    cout << ans << endl;
}
