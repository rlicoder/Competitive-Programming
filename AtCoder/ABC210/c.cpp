#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        m[a[i]]++;
    }
    int l = 0;
    int r = k-1;
    int ans = m.size();
    while (r+1 < n)
    {
        r++;
        m[a[r]]++;
        m[a[l]]--;
        if (m[a[l]] == 0)
        {
            m.erase(a[l]);
        }
        l++;
        ans = max(ans, (int)m.size());
    }
    cout << ans;
}
