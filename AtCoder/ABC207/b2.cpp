#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    //cyan = a + bx
    //red = cx
    //so look for x such that a + b*x <= d*c*x
    //a <= d*c*x - b*x
    //a <= x(dc - b)
    //if dc-b < 0, impossible
    //else x can be at most a if dc-b == 1 (worst case)
    int ans = -1;
    for (int i = 1; i <= a; i++)
    {
        if (i * (d*c-b) >= a)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
