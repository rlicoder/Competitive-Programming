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
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            ans++;
            i++;
            while (i < n && a[i] == 1)
            {
                ans++;
                i++;
            }
            if (i < n && a[i] == 0)
            {
                ans += 2;
                while (i < n && a[i] == 0)
                {
                    i++;
                }
            }
        }
    }
    cout << ans;
}
