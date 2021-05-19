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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int l,r;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            l = a[i-1];
            r = a[i];
            while (r <= l)
            {
                r *= 10;
                ans++;
            }
            a[i] = r;
        }
        for (auto it : a)
        {
            cout << it << " ";
        }
        cout << endl;
        cout << ans << endl;
    }

}


