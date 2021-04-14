#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,r,k;
    cin >> n >> r >> k;
    int ans = 0;
    if (r >= k)
    {
        ans = r;
        if (r < n)
        {
            ans = n;
            ans += ((r%2 != n%2) ? 1 : 0);
        }
    }
    else if (k > r)
    {
        ans = 2*k-r;
        if (ans < n)
        {
            ans = n;
            ans += (((2*k-r)%2 != n%2) ? 1 : 0);
        }
    }
    ans += r;
    cout << ans << endl;
}
