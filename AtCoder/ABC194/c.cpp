#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    map<long long,long long> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (auto j = next(it); j != m.end(); j++)
        {
            ans += it->second * j->second * pow(it->first - j->first, 2);
        }
    }
    cout << ans;
}
