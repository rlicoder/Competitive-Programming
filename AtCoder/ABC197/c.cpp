#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < (1<<(n-1)); i++)
    {
        int in, out;
        in = out = 0;
        for (int j = 0; j < n; j++)
        {
            in |= a[j];
            if (i&1<<j)
            {
                out ^= in;
                in = 0;
            }
        }
        out ^= in;
        ans = min(ans, out);
    }
    cout << ans << endl;
}
