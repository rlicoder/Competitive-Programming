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
    int n;
    cin >> n;
    vector<bitset<3000>> a(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        bitset<3000> x(str);
        a[i] = x;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            long long c = (a[i]&a[j]).count();
            ans += c * (c-1) / 2;
        }
    }
    cout << ans << endl;
}

