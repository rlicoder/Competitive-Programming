#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
const ll mod = 1000000007;
 
using namespace std;
 
main()
{
    int n;
    cin >> n;
    if (n%2 == 1)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << " " << i - 1 << " ";
        }
    }
}