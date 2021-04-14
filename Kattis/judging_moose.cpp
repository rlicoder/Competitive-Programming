#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    if (n==m && n != 0)
    {
        cout << "Even " << n*2 << endl;
    }
    else if (n != m)
    {
        cout << "Odd " << max(n,m) * 2 << endl;
    }
    else if (n == 0 && n == m)
    {
        cout << "Not a moose" << endl;
    }

}


