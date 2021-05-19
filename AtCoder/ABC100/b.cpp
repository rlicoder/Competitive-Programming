#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;
    if (d == 0)
    {
        cout << n + (n/100);
    }
    else if (d == 1)
    {
        cout << (n + n/100)*100;
    }
    else
    {
        cout << (n+n/100) * 100 * 100;
    }

}
