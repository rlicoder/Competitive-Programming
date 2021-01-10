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
    sort(a.begin(), a.end());
    int ans = 0;
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= curr)
        {
            ans++;
            curr++;
        }
    }
    cout << ans << endl;
}
