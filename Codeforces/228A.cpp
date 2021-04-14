#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
const ll mod = 1000000007;
 
using namespace std;
 
main()
{
    set<int> s;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << 4 - s.size();
}