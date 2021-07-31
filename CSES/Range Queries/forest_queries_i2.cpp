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
        }
    }
    vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + a[i-1][j-1];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        //y1--;
        //x1--;
        //y2--;
        //x2--;
        cout << pref[y2][x2] - pref[y1-1][x2] - pref[y2][x1-1] + pref[y1-1][x1-1] << endl;
    }
}

