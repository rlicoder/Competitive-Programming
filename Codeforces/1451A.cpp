#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int ans = 0;
        while (n != 1)
        {
            if (n%2==0 && n != 2)
            {
                n /= (n/2);
            }
            else
            {
                n--;
            }
            ans++;
        }
        cout << ans << endl;
    }
}


