#include <bits/stdc++.h>

using namespace std;

int main()
{
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
    cout << "time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
}

