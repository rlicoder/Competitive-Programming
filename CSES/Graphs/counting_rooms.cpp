#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> vis(n,vector<bool>(m, false));
    queue<pair<int,int>> q;

    function<bool(int,int)> valid = [&] (int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    function<void(int,int)> dfs = [&] (int i, int j)
    {
        vis[i][j] = true;
        if (valid(i+1,j) && !vis[i+1][j] && a[i+1][j] == '.')
        {
            vis[i+1][j] = true;
            dfs(i+1,j);
        }
        if (valid(i-1,j) && !vis[i-1][j] && a[i-1][j] == '.')
        {
            vis[i-1][j] = true;
            dfs(i-1,j);
        }
        if (valid(i,j+1) && !vis[i][j+1] && a[i][j+1] == '.')
        {
            vis[i][j+1] = true;
            dfs(i,j+1);
        }
        if (valid(i,j-1) && !vis[i][j-1] && a[i][j-1] == '.')
        {
            vis[i][j-1] = true;
            dfs(i,j-1);
        }
    };
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
}
