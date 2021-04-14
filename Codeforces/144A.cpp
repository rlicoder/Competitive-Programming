#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int high, low;
    high = 0; low = 1e9;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        high = max(high, a[i]);
        low = min(low, a[i]);
    }
    int highpos, lowpos;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == high)
        {
            highpos = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] == low)
        {
            lowpos = i;
            break;
        }
    }
    int ans = highpos + abs(n-1-lowpos);
    if (highpos > lowpos)
    {
        ans-=1;
    }
    cout << ans << endl;

}

