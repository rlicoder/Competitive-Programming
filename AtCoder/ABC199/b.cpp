#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int hi = INT_MAX;
    int lo = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        lo = max(lo, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        hi = min(hi, b[i]);
    }
    if (hi - lo + 1 <= 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << hi - lo + 1 << endl;
    }
}
