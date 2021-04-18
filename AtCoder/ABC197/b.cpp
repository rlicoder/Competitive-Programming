#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    x--;y--;
    vector<vector<char>> a(n, vector<char>(m, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 1;
    for (int i = x+1; i < n && i >= 0; i++)
    {
        if (a[i][y] == '.')
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    for (int i = x-1; i < n && i >= 0; i--)
    {
        if (a[i][y] == '.')
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    for (int i = y-1; i < m && i >= 0; i--)
    {
        if (a[x][i] == '.')
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    for (int i = y+1; i < m; i++)
    {
        if (a[x][i] == '.')
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans;
}
