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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i-1])
        {
            ans += abs(a[i] - a[i-1]);
            a[i] += abs(a[i] - a[i-1]);
        }
    }
    cout << ans << endl;
    
