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
        vector<long long> c(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        long long ans = 2e18;
        vector<long long> lo(n, 2e18);
        vector<long long> num(n, n);
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            lo[i%2] = min(lo[i%2], c[i]);
            num[i%2]--;
            sum += c[i];
            if (i > 0)
            {
                long long cur = sum + num[0] * lo[0] + num[1] * lo[1];
                ans = min(ans, cur);
            }

        }
        cout << ans << endl;
    }
}




