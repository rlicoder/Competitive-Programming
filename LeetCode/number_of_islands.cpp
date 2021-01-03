#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis (n, vector<bool>(m,false));
    stack<pair<int,int>> s;
    int ans = 0;
    function<void(pair<int,int>)> dfs = [&] (pair<int,int> c)
    {
        s.pop();
        int x = c.first;
        int y = c.second;
        vis[x][y] = true;
        if (x+1 < n && x+1 >= 0 && y < m && y >= 0 && vis[x+1][y] == false && grid[x+1][y] == '1')
        {
            vis[x+1][y] = true;
            s.push({x+1,y});
        }
        if (x-1 < n && x-1 >=0 && y < m && y >=0 && vis[x-1][y] == false && grid[x-1][y] == '1')
        {
            vis[x-1][y] = true;
            s.push({x-1,y});
        }
        if (x < n && x >= 0 && y+1 < m && y+1 >= 0 && vis[x][y+1] == false && grid[x][y+1] == '1')
        {
            vis[x][y+1] = true;
            s.push({x,y+1});
        }
        if (x < n && x >= 0 && y-1 < m && y-1 >= 0 && vis[x][y-1] == false && grid[x][y-1] == '1')
        {
            vis[x][y-1] = true;
            s.push({x,y-1});
        }
        if (s.empty())
        {
            return;
        }
        dfs(s.top());
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && grid[i][j] == '1')
            {
                ans++;
                s.push({i,j});
                dfs(s.top());
            }
        }
    }
    cout <<  ans;
}
