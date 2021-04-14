#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a (n+1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> side(n+1,-1);
    vector<bool> vis(n+1, false);
    for (int i = 0; i < a.size(); i++)
    {
        if (vis[i] == false)
        {
            queue<int>q;
            q.push(i);
            side[i] = 1;
            vis[i] = true;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto it : a[cur])
                {
                    if (!vis[it])
                    {
                        if (side[it] == -1 && side[it] != side[cur])
                        {
                            side[it] = (side[cur]==1?2:1);
                            vis[it] = true;
                            q.push(it);
                        }
                        else
                        {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                    }
                    else
                    {
                        if (side[it] == side[cur])
                        {
                            cout << "IMPOSSIBLE" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i < side.size(); i++)
    {
        cout << side[i] << " ";
    }
}
