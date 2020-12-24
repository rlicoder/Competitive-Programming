#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
const ll mod = 1000000007;
 
using namespace std;
 
main()
{
    int count = 0;
    int n, m;
    cin >> n >> m;
    int x = max(n,m);
    for (int i = 0 ; i <= x; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (i*i + j == n && j*j + i == m)
            {
                count++;
            }
        }
    }
    cout << count;
}