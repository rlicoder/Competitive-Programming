#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<long long> pref(n+1);
    pref[0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        pref[i] = pref[i-1] + (str[i-1] - 'a' + 1);
    }
    for (long long i = 0; i < q; i++)
    {
        long long l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1]  << endl;
    }
}
