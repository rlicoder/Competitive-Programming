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
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int lb = 0;
    int lg = 0;
    int ans = 0;
    while (lb < a.size() && lg < b.size())
    {
        if (abs(a[lb] - b[lg]) <= 1)
        {
            ans++;
            lb++;
            lg++;
        }
        else
        {
            while (lb < a.size() && a[lb] + 1 < b[lg])
            {
                lb++;
            }
            while (lg < b.size() && b[lg] + 1 < a[lb])
            {
                lg++;
            }
        }

    }
    cout << ans << endl;
}
