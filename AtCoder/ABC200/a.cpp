#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = n / 100;
    if (n % 100 != 0)
    {
        ans += 1;
    }
    cout << ans;
}
