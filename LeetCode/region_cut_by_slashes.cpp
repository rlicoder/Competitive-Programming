#include <bits/stdc++.h>

using namespace std;

int main()
{
    int height, width;
    vector<string> grid;
    for (int i = 0; i < 2; i++)
    {
        string str;
        getline(cin,str);
        grid.push_back(str);
    }
    height = grid.size();
    width = grid[0].size();
    int ans = 0;
    vector<vector<vector<bool>>> vis(height, vector<vector<bool>> (width, vector<bool>(4, false)));
    function<bool(int,int)> valid = [&] (int r, int c)
    {
        return r >= 0 && r < height && c >= 0 && c < width;
    };

    function<void(int,int,int)> dfs = [&] (int r, int c, int t)
    {
        
        if (valid(r,c) && vis[r][c][t] != true)
        {
            vis[r][c][t] = true;
            if (t == 0)
            {
                dfs(r-1,c,2);
            }
            else if (t == 1)
            {
                dfs(r,c+1,3);
            }
            else if (t == 2)
            {
                dfs(r+1,c,0);
            }
            else if (t == 3)
            {
                dfs(r,c-1,1);
            }
            else
            {
                assert(false);
            }

            
            if (grid[r][c] == '/')
            {
                if (t == 0)
                {
                    dfs(r,c,3);
                }
                else if (t == 3)
                {
                    dfs(r,c,0);
                }
                else if (t == 1)
                {
                    dfs(r,c,2);
                }
                else if (t == 2)
                {
                    dfs(r,c,1);
                }
                else
                {
                    assert(false);
                }
            }
            else if (grid[r][c] == '\\')
            {
                if (t == 0)
                {
                    dfs(r,c,1);
                }
                else if (t == 1)
                {
                    dfs(r,c,0);
                }
                else if (t == 3)
                {
                    dfs(r,c,2);
                }
                else if (t == 2)
                {
                    dfs(r,c,3);
                }
                else
                {
                    assert(false);
                }
            }
            else 
            {
                for (int i = 0 ; i < 4; i++)
                {
                    if (!vis[r][c][i] && t != i)
                    {
                        dfs(r,c,i);
                    }
                }
            }

        }
    };

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int t = 0; t < 4; t++)
            {
                if (!vis[i][j][t])
                {
                    ans++;
                    dfs(i, j, t);
                }
            }
        }
    }
    cout << ans;
}
