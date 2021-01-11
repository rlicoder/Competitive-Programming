#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        if (m.count(x) == 1)
        {
            m[x] = max(m[x], y);
        }
        else
        {
            m[x] = y;
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x,y;
        cin >> x >> y;
        if (m.count(x) == 1)
        {
            m[x] = max(m[x], y);
        }
        else
        {
            m[x] = y;
        }
    }
    long long ans = 0;
    for (auto it : m)
    {
        ans += it.second;
    }
    cout << ans;

}
