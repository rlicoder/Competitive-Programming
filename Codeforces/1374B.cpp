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
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int three;
        int two;
        two = three = 0;
        bool ok = true;
        while (n!=1)
        {
            if (n%2 == 0)
            {
                two++;
                n /= 2;
            }
            else if (n % 3 == 0)
            {
                three++;
                n /= 3;
            }
            else
            {
                ok = false;
                break;
            }
        }
        int ans = 0;
        if (three >= two && ok)
        {
            ok = true;
            ans = three + abs(three-two);
        }
        else
        {
            ok = false;
        }
        if (ok)
        {
            cout << ans << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

            

        

