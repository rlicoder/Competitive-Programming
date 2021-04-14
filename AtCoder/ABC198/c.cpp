#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,x,y;
    cin >> r >> x >> y;
    long double dist = sqrt((pow(x,2)) + (pow(y,2)));
    if (r > dist)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << ceil (dist/r) << endl;
    }
}
