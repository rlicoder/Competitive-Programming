#include <bits/stdc++.h>

using namespace std;

long long powten(long long x)
{
    long long test = 1;
    if (x == 0 | x == 1)
    {
        return 10;
    }
    while (x >= test)
    {
        test *= 10;
    }
    return test;
}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n,x;
        long long ans = 0;
        cin >> n >> x;
        long long ten = 1;
        if (n == 0)
        {
            cout << -1 << endl;
            continue;
        }
        while (abs(x-powten(x)) * to_string(x).size() <= n)
        {
            n -= abs(x-powten(x)) * to_string(x).size();

            ans += abs(x-powten(x));
            x = powten(x);
        }
        if (n > 0)
        {
            if (n%to_string(x).size() != 0)
            {
                ans = -1;
            }
            else
            {
                ans += n / to_string(x).size();
            }
        }
            
        cout << ans << endl;
    }
}

