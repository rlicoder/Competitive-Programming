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
        int ans = 0;
        while (n != 1)
        {
            while (n%2 == 0)
            {
                n /= 2;
                ans++;
            }
            while (n%3 == 0)
            {
                n *= 2;
                n /= 3;
                ans++;
            }
            while (n%5 == 0)
            {
                n *= 4;
                n /= 5;
                ans++;
            }
            if (n%2 != 0 && n%3 != 0 && n%5 != 0 && n != 1)
            {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
}
