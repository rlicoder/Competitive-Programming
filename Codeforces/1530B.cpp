#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> a(n, vector<bool> (m, false));
        a[0][0] = 1;
        a[0][m-1] = 1;
        a[n-1][0] = 1;
        a[n-1][m-1] = 1;
        function<bool(int,int)> valid = [&] (int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!(i == 0 || j == 0 || j == m-1 || i== n-1))
                {
                    continue;
                }
                bool ok = true;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == y && y == 0)
                        {
                            continue;
                        }
                        if (valid(i+x, j+y))
                        {
                            if (a[i+x][j+y] == 1)
                            {
                                ok = false;
                            }
                        }
                    }
                }
                if (ok)
                {
                    a[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}
