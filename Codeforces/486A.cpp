#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n%2)
    {
        cout << -1 * (n/2 + 1);
        cout << endl;
    }
    else
    {
        cout << n/2 << endl;
    }
}

