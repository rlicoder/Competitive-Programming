#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >>tc;
    while (tc--)
    {
        int x,y;
        cin >> x >> y;
        int ans = 0;
        if (x == 0 && y == 0)
        {
            ans = 0;
        }
        else if (x == 0 || y == 0)
        {
             ans = 2*max(x,y)-1;
        }
        else if (x == y)
        {
            ans = x+y;
        }
        else if (x == min(x,y))
        {
            ans +=2* x;
            y-=x;
            x= 0;
            if (y == 1)
            {
                ans +=1;
            }
            else
            {
                ans += y*2-1;
            }
        }
        else
        {
            ans +=2* y;
            x-=y;
            y= 0;
            if (x == 1)
            {
                ans += 1;
            }
            else
            {
                ans += x*2-1;
            }
        }
        cout << ans << endl;
        



    }
}

