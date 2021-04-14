#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int x,y;
        cin >> x >> y;
        //using a separate program, I found that for every even (except 2) number, you can go to infinity (theory but i saw large numbers)
        //so there is only a limit for values 1,2,3
        //limits are 0==0
        //1==0
        //we can generalize the 2 as if y = 0, then true, since you can always subtract 1
        //2==3
        if (y == 0)
        {
            cout << "YES";
        }
        else if (x == 3 && y <= 3)
        {
            cout << "YES";
        }
        else if (x == 2 && y <= 3)
        {
            cout << "YES";
        }
        else if (x == 1 && y <= 1)
        {
            cout << "YES";
        }
        else if (x >= 4)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}
