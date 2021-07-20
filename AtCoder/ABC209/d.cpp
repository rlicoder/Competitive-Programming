#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int Q;
    cin >> Q;
    vector<vector<int>> a(n+1, vector<int>());
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vector<int> dis(n+1, -1);
    dis[1] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int it : a[t])
        {
            if (dis[it] == -1)
            {
                dis[it] = dis[t] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        //cout << dis[x] << " " << dis[y] << endl;
        if ((dis[x] % 2) == (dis[y] % 2))
        {
            cout << "Town" << endl; 
        }
        else
        {
            cout << "Road" << endl;
        }
    }
}
