#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        int count = 0;
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            count++;
            int j = i + 1;
            while (j < n && a[j].second == a[j-1].second+1)
            {
                j++;
            }
            i = j - 1;
        }
        cout << (count <= k ? "Yes" : "No") << endl;
    }
}
