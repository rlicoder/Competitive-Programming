#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    if (c > b)
    {
        long long l = 1;
        long long r = 2e18;
        long long count = 0;
        long long ans = 0;
        while (l < r)
        {
            long long mid = (l + r) / 2;
            long long num = a + mid * b;
            long long den = mid * c;
            if (den * d >= num)
            {
                r = mid;
                ans = mid;
            }
            else
            {
                l = mid;
            }
            count++;
            if (count == 100)
            {
                break;
            }
        }
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
