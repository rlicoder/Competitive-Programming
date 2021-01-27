#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = 0;
        int r = n-1;
        int ans = 0;
        while (l < r)
        {
            if (a[l] + a[r] <= x)
            {
                ans++;
                l++;r--;
            }
            else
            {
                r--;
            }
        }
        cout << ans << endl;
    }
}
