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
        if (n%2)
        {
            cout << n/2 << endl;
        }
        else
        {
            cout << n/2-1 << endl;
        }
    }
}
