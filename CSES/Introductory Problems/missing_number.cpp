#include <bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl '\n'
 
const int mod = 1000000007;
const int INF = INT_MAX;
 
using namespace std;
 
main()
{
    ll n;
    cin >> n;
    ll total = n * (n+1) / 2;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cout << total - sum;
}
