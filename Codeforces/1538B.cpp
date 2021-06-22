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
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }
        if (total % n != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int avg = total / n;
            int ans = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] > avg)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
}
