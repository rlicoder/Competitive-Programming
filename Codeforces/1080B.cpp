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
        long long start,end;
        x--;
        if (x%2)
        {
            start = -1 * ((x+1)/2);
        }
        else
        {
            start = x/2;
        }
        if (y%2)
        {
            end = -1 * ((y+1)/2);
        }
        else
        {
            end = y/2;
        }
        cout << end - start << endl;
    }
}
