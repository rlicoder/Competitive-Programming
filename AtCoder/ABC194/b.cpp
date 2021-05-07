#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, a[i] + b[i]);
    }
    int x = min_element(a.begin(), a.end()) - a.begin();
    int low = a[x];
    for (int i = 0; i < n; i++)
    {
        if (i == x)
        {
            continue;
        }
        ans = min(ans, max(a[x], b[i]));
    }
    cout << ans << endl;

}
