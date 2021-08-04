#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    bool found = false;
    for (int i = 0; i < n-3 && !found; i++)
    {
        int anchor = a[i].first;
        for (int j = i+1; j < n-2 && !found; j++)
        {
            int l = j+1;
            int r = n-1;
            while (l < r && !found)
            {
                int sum = anchor + a[j].first + a[l].first + a[r].first;
                if (sum == x)
                {
                    found = true;
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second << endl;
                }
                else if (sum < x)
                {
                    l++;
                }
                else if (sum > x)
                {
                    r--;
                }
            }
        }
    }
    if (!found)
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
