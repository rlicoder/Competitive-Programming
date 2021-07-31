#include <bits/stdc++.h>
 
const long long INF = 1e18;
 
using namespace std;
 
int main()
{
    long long n,m;
    cin >> n >> m;
    vector<vector<pair<long long,long long>>> adj (n+1, vector<pair<long long,long long>>());
    for (long long i = 0; i < m; i++)
    {
        long long x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<bool> vis(n+1, false);
    vector<long long> dp (n+1, INF);
    pq.push({0,1});
    dp[1] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        pq.pop();
        if (vis[cur])
        {
            continue;
        }
        vis[cur] = true;
        for (auto [dest, weight]: adj[cur])
        {
            if (dp[cur] + weight < dp[dest])
            {
                dp[dest] = dp[cur] + weight;
                pq.push({dp[dest], dest});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
}
