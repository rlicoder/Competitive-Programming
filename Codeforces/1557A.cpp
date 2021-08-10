#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<long double> a(n);
        long double hi = -1e9;
        long double total = 0;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            a[i] = stod(str);
            hi = max(hi, a[i]);
            total += a[i];
        }
        total -= hi;
        cout << fixed << setprecision(6);
        cout << hi + (total / ((long double)n-1)) << endl;
    }
}
