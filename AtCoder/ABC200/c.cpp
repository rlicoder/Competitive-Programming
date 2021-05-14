#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    map<long long,long long> f;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        f[a[i] % 200]++;
    }
    long long ans = 0;
    for (auto it : f)
    {
        ans += ((it.second * (it.second - 1) / 2));
    }
    cout << ans << endl;
}
