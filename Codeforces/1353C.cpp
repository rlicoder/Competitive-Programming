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
        long long ans = 0;
        long long levels = n/2;
        while (levels)
        {
            ans += levels * (levels*8);
            levels--;
        }
        cout << ans << endl;
    }
}
