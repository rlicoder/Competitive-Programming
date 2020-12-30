#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long k,p,n;
        cin >> k >> p >> n;
        if (k-p < 0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << (k-p) * n << endl;
    }
}

