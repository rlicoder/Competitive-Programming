#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
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
        hi++;lo++;
        int ans = min({lo + hi, (n-lo) + (n-hi) - 2, lo + (n-hi) - 1, hi + (n-lo) - 1});

        cout << ans << endl;
    }
}
