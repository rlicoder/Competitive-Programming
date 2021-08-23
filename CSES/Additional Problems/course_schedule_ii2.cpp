#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> in(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            pq.push(i);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        int cur = pq.top();
        ans.push_back(cur);
        pq.pop();
        for (auto it : adj[cur]) 
        {
            in[it]--;
            if (in[it] == 0)
            {
                pq.push(it);
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
