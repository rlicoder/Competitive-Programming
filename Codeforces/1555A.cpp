#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        //  6  8  10
        // 15 20  25
        n = (n%2 ? n+1 : n);
        if (n < 7)
        {
            cout << 15 << endl;
        }
        else
        {
            long long x = n / 6;
            n %= 6;
            long long ans = 0;
            ans += 15 * x;
            if (n == 2)
            {
                ans -= 15;
                ans += 20;
            }
            else if (n == 4)
            {
                ans -= 15;
                ans += 25;
            }
            cout << ans << endl;
        }
    }
}
