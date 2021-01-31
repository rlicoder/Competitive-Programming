#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    pair<int,int> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                start.first = i;
                start.second = j;
            }
        }
    }
    queue<pair<pair<int,int>,char>> q;
    vector<char>ans;
    q.push({start,0});
    
    function<bool(int,int)> valid = [&](int i, int j)
    {
        return i >= 0 &&  i < n && j >= 0 && j < m && (a[i][j] == '.' || a[i][j] == 'B');
    };
    bool found = false;
    function<void(int,int,char)> bfs = [&] (int i, int j, char dir)
    {
        q.pop();
        if (a[i][j] == 'B')
        {
            found = true;
            while (true)
            {
                ans.push_back(dir);
                if (dir == 'L')
                {
                    j++;
                }
                else if (dir == 'R')
                {
                    j--;
                }
                else if (dir == 'U')
                {
                    i++;
                }
                else if (dir == 'D')
                {
                    i--;
                }
                else if (dir == 'A')
                {
                    ans.pop_back();
                    break;
                }
                dir = a[i][j];
            }
            return;
        }
        a[i][j] = dir;
        //cout << i << " " << j << endl;
        if (valid(i+1,j) && !found)
        {
            a[i+1][j] = (a[i+1][j] == 'B' ? 'B' : dir);
            q.push({{i+1,j},'D'});
        }
        if (valid(i-1,j) && !found)
        {
            a[i-1][j] = (a[i-1][j] == 'B' ? 'B' : dir);
            q.push({{i-1,j},'U'});
        }
        if (valid(i,j+1) && !found)
        {
            a[i][j+1] = (a[i][j+1] == 'B' ? 'B' : dir);
            q.push({{i,j+1},'R'});
        }
        if (valid(i,j-1) && !found)
        {
            a[i][j-1] = (a[i][j-1] == 'B' ? 'B' : dir);
            q.push({{i,j-1},'L'});
        }
        if (!q.empty() && !found)
        {
            bfs(q.front().first.first, q.front().first.second, q.front().second);
        }
    };
    bfs(q.front().first.first, q.front().first.second, 'A');

    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++)
    //    {
    //        cout<<a[i][j];
    //    }
    //    cout << endl;
    //}

    if (found)
    {
        cout << "YES" << endl;
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto it : ans)
        {
            cout << it;
        }
    }
    else
    {
        cout << "NO";
    }
}
