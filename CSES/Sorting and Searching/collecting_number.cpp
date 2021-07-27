#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int ans = 1;
    for (int i = n; i > 1; i--)
    {
        if (pos[i] < pos[i-1])
        {
            ans++;
            //cout << i << " comes before " << i-1 << endl;
            //cout << pos[i] << " " << pos[i-1] << endl;
        }
    }
    cout << ans;
}
