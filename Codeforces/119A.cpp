#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,n;
    cin >> a >> b >> n;
    bool simon;
    while (true)
    {
        if (__gcd(a, n) <= n)
        {
            int take = __gcd(a,n);
            n -= take;
        }
        else
        {
            simon = false;
            break;
        }
        if (__gcd(b,n) <= n)
        {
            int take = __gcd(b,n);
            n -= take;
        }
        else
        {
            simon = true;
            break;
        }
    }
    cout << (simon?'0':'1');
}
