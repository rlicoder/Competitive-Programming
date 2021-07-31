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
        vector<vector<pair<int,int>>> a(5, vector<pair<int,int>>(n));
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                cin >> a[i][j].first;
                a[i][j].second = j+1;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            sort(a[i].begin(), a[i].end());
        }
        map<int,int> m;
        bool found = false;
        for (int i = 0; i < 5; i++)
        {
            m[a[i][0].second]++;
        }
        for(auto it : m)
        {
            if (it.second >= 3)
            {
                cout << it.first << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << -1 << endl;
        }
    }
}
