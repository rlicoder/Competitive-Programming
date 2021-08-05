#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, x;
    cin >> n >> x;
    vector<long long> a, b;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        if (i % 2 == 0)
        {
            a.push_back(x);
        }
        else
        {
            b.push_back(x);
        }
    }
    unordered_map<long long,long long> ma,mb;
    ma.reserve(1<<(a.size()));
    mb.reserve(1<<(b.size()));
    for (long long i = 0; i < (1<<(a.size())); i++)
    {
        long long sum = 0;
        for (long long j = 0; j < (a.size()); j++)
        {
            if (i&(1<<j))
            {
                sum += a[j];
            }
        }
        ma[sum]++;
    }
    for (long long i = 0; i < (1<<(b.size())); i++)
    {
        long long sum = 0;
        for (long long j = 0; j < (b.size()); j++)
        {
            if (i&(1<<j))
            {
                sum += b[j];
            }
        }
        mb[sum]++;
    }       
    long long ans = 0;
    for (auto it : ma)
    {
        long long need = x - it.first;
        if (need >= 0)
        {
            long long cnt = mb[need];
            ans += it.second * cnt;
        }
    }
    cout << ans << endl;
}
