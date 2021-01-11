#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,k;
    cin >> n >> k;
    long long ans = 0;
    ans += 3*n;
    ans += min(abs(k-1),abs(k-n));
    cout << ans << endl;
}
