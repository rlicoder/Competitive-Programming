#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int,3>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x,y,z;
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int ans = 2e9;
    for (int i = 0; i < n; i++)
    {
        if (a[i][2] - a[i][0] > 0)
        {
            ans = min(ans, a[i][1]);
        }
    }
    cout << (ans == 2e9 ? -1 : ans) << endl;
}
