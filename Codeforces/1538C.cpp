#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        map<int,int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
        //sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= r)
            {
                for (int j = l - a[i]; j <= r - a[i]; j++)
                {
                    if (m.count(j))
                    {
                        if (j == a[i])
                        {
                            m[j]--;
                        }
                        ans += (m[j] >= 0 ? m[j] : 0);
                    }
                }
            }
        }
        cout << ans/2 << endl;
    }
}
