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
        sort(a.begin(), a.end());
        int ans = 2e3;
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, abs(a[i] - a[i-1]));
        }
        cout << ans << endl;
    }
}
                    


