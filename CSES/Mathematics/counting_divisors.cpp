#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int x;
        cin >> x;
        int ans = 0;
        int i = 1;
        for (; i * i < x; i++)
        {
            if (x % i == 0)
            {
                ans++;
            }
        }
        ans *= 2;
        if (i * i == x)
        {
            ans++;
        }
        cout << ans << endl;
    }
}
