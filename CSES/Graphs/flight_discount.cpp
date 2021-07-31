#include <bits/stdc++.h>

const long long INF = 1e18;

using namespace std;

int main()
{
    long long n,m;
    cin >> n >> m;
    vector<vector<pair<long long,long long>>> adj (n+1, vector<pair<long long,long long>>());
    vector<array<long long,3>> his;
    for (long long i = 0; i < m; i++)
    {
        long long x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        his.push_back({x,y,z});
    }
    function<bool(array<long long,3>, array<long long,3>)> cus = [&] (array<long long, 3> x, array<long long,3> y)
    {
        return x[2] > y[2];
    };
    sort(his.begin(), his.end(), cus);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    vector<bool> vis(n+1, false);
    vector<long long> dp (n+1, INF);
    pq.push({0,1});
    dp[1] = 0;
    while (!pq.empty())
    {
        long long cur = pq.top().second;
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
    long long lo = dp[n];
    for (long long i = 0; i < min((long long)100, m); i++)
    {
        long long orig = 0;
        array<long long, 3> hi = his[i];
        pair<long long,long long> pos;
        for (long long j = 0; j < adj[hi[0]].size(); j++)
        {
            if (adj[hi[0]][j] == make_pair(hi[1], hi[2]))
            {
                pos = {hi[0], j};
                orig = adj[hi[0]][j].second;
                adj[pos.first][pos.second].second /= 2;
                break;
            }
        }
        vis = vector<bool> (n+1, false);
        dp = vector<long long> (n+1, INF);
        pq.push({0,1});
        dp[1] = 0;
        vector<pair<long long, long long>> p(n+1);
        while (!pq.empty())
        {
            long long cur = pq.top().second;
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
                    p[dest] = {cur, weight};
                }
            }
        }
        lo = min(lo, dp[n]);
        adj[pos.first][pos.second].second = orig;
    }
    cout << lo << endl;
}
