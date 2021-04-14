#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c,p,x,l;
    cin >> c >> p >> x >> l;
    vector<vector<int>> a(c+1, vector<int>());
    for (int i = 0; i < p; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int>sz(c+1);
    for (int i = 1; i <= c; i++)
    {
        sz[i] = a[i].size();
    }
    queue<int> q;
    q.push(l);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        sz[cur] = 0;
        for (auto it : a[cur])
        {
            if (sz[it] != 0)
            {
                sz[it]--;
                if (sz[it] == a[it].size()/2)
                {
                    q.push(it);
                }
            }
        }
    }
    cout << (sz[x] == 0 ? "leave" : "stay");
}
