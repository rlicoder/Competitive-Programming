#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = upper_bound(a.begin(), a.end(),x);
        if (it == a.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
           a.erase(it);
        }
    }
} 
