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
        if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        vector<vector<int>> a(n, vector<int> (n,0));
        vector<vector<bool>> v(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i + j) % 2  == 0)
                {
                    v[i][j] = true;
                }
            }
        }
        int c = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j])
                {
                    a[i][j] = c++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!v[i][j])
                {
                    a[i][j] = c++;
                }
                cout << a[i][j] << " \n"[j+1==n];
            }
        }
    }
}
