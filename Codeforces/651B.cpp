#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b = a;
    set<int> s;
    int ans = 0;
    do
    {
        int hi = b[0];
        vector<int> c;
        for (int i = 1; i < b.size(); i++)
        {
            if (b[i] > hi)
            {
                ans++;
                hi = b[i];
            }
            else
            {
                c.push_back(b[i]);
            }
        }
        b = c;
    }
    while (b.size());
    cout << ans;
}

