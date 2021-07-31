#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            if (x == '*')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    vector<vector<int>> pref(n, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pref[i][j+1] = a[i][j] + pref[i][j];
        }
    }
    //for (auto it : pref)
    //{
    //    for (auto x : it)
    //    {
    //        cout << x << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        int sum = 0;
        y1--;y2--;
        for (int j = y1; j <= y2; j++)
        {
            //cout << pref[j][x2] << " - " << pref[j][x1-1] << endl;
            sum += pref[j][x2] - pref[j][x1-1];
        }
        cout << sum << endl;
    }
}
