#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        ans += a.back();
        bool found = false;
        a.erase(a.end()-1);
        for (int i = 0; i < 2; i++)
        {
            if (a.back() * (*(a.end()-2)) * ans > a[0] * ans * a[1])
            {
                ans *= a.back() * *(a.end()-2);
                a.erase(a.end()-1);
                a.erase(a.end()-1);
            }
            else
            {
                ans *= a[0] * a[1];
                a.erase(a.begin());
                a.erase(a.begin());
            }
        }
        cout << ans << endl;
    }
}
