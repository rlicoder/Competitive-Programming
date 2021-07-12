#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long a,b,c,d;
        cin >> a >> b >> c >> d;
        long long cur = b;
        if (d >= c && a < b)
        {
            cout << -1 << endl;
        }
        else if (a > b)
        {
            cout << 0 << endl;
        }
        else
        {
            long long need = a - b;
            long long x = ceil(need / (c - d));
            cur += x * d;
            cout << cur << endl;
        }
    }
}
