#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    int x = min(a,min(c,d));
    ans += x*256;
    a -= x;
    ans += 32*min(a,b);
    cout << ans;
}
