#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long l = 0;
    long long r = 1e9;
    long long ans = -1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long num = a + mid * b;
        long long den = mid * c;
        if (den * d >= num)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
