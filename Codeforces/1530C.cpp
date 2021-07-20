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
        vector<int> a(n), b(n);
        int ta, tb;
        ta = tb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ta += a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            tb += b[i];
        }
        priority_queue<int, vector<int>, greater<int>> pa(a.begin(), a.end()), pb(b.begin(), b.end());

        int l = 0;
        int r = 1e5;
        //100 * 1e5 to your 1e5 * 0
        while (l <= r)
        {
            int m = (l + r) / 2;

            priority_queue<int,vector<int>, greater<int>> ca = pa;

            int cta = ta;
            int ctb = tb;

            for (int i = 0; i < (n + m) / 4; i++)
            {
                cta -= ca.top();
                ca.pop();
            }
            cta += 100 * m;
            if (cta > )

        }


    }

}
