#include <bits/stdc++.h>

const long long mod = 1e9 + 7;

using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> c(n);
    long long total = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    total += c[0];
    for (long long i = 1; i < c.size(); i++)
    {
        total %= mod;
        long long x = (c[i] - i);
        if (x < 0)
        {
            cout << 0 << endl;
            exit(0);
        }
        total *= x;
        total %= mod;
    }
    cout << total << endl;
}
