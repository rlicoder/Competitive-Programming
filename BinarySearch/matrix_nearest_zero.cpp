vector<vector<int>> solve(vector<vector<int>>& a) 
{
    int n = a.size();
    int m = a[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));

    function<bool(int,int)> valid = [&] (int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    };
    
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                q.push({i,j});
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        vis[i][j] = true;
        if (valid(i-1,j) && !vis[i-1][j] && a[i-1][j] == 1)
        {
            dist[i-1][j] = 1 + dist[i][j];
            q.push({i-1,j});
            vis[i-1][j] = true;
        }
        if (valid(i+1,j) && !vis[i+1][j] && a[i+1][j] == 1)
        {
            dist[i+1][j] = 1 + dist[i][j];
            q.push({i+1,j});
            vis[i+1][j] = true;
        }
        if (valid(i,j-1) && !vis[i][j-1] && a[i][j-1] == 1)
        {
            dist[i][j-1] = 1 + dist[i][j];
            q.push({i,j-1});
            vis[i][j-1] = true;
        }
        if (valid(i,j+1) && !vis[i][j+1] && a[i][j+1] == 1)
        {
            dist[i][j+1] = 1 + dist[i][j];
            q.push({i,j+1});
            vis[i][j+1] = true;
        }
    }
    return dist;

}
