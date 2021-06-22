#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int hi = max_element(a.begin(), a.end()) - a.begin();
        int lo = min_element(a.begin(), a.end()) - a.begin();
        int ans = min({/*remove from left only*/ max(hi, lo) + 1,
                       /*remove hi from left, lo from right*/ hi + 1 + (n - lo),
                       /*remove hi from right, lo from left*/ lo + 1 + (n - hi),
                       /*remove both from the lright*/ n - min(lo,hi)
                });
        cout << ans << endl;
    }
}
