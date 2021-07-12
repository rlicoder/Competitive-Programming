#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int ax,ay,bx,by,fx,fy;
        cin >> ax >> ay >> bx >> by >> fx >> fy;
        int ans = abs(bx-ax) + abs(by-ay);
        if (bx == ax && ax == fx && (ay < fy && by > fy || ay > fy && by < fy))
        {
            ans += 2;
        }
        else if (by == ay && ay == fy && (ax < fx && bx > fx || ax > fx && bx < fx))
        {
            ans += 2;
        }
        cout << ans << endl;
    }
}
