#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int a,b,c;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> a;
    for (int i = 0; i < m; i++)
    {
        edge e;
        cin >> e.a >> e.b >> e.c;
        e.a--;
        e.b--;
        a.push_back(e);
    }
    //sort(a.begin(), a.end(), [] (edge x, edge y) { return x.c < y.c; });
    const int INF = 1e9;
    vector<int> dp (n, INF);
    bool nega = false;
    vector<int> p (n, -1);
    int cycle_end = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            if (dp[a[j].b] > dp[a[j].a] + a[j].c)
            {
                dp[a[j].b] = max(-INF, dp[a[j].a] + a[j].c);
                p[a[j].b] = a[j].a;
                if (i == n-1)
                {
                    cycle_end = a[j].b;
                }
            }
        }
    }
    if (cycle_end == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        int y = cycle_end;
        y = p[y];

        set<int> s;
        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back(cur);
            if (s.count(cur))
            {
                break;
            }
            s.insert(cur);
        }
        reverse(path.begin(), path.end());
        while (path.back() != path[0])
        {
            path.pop_back();
        }
        for (auto it : path)
        {
            cout << it+1 << " ";
        }
        cout << endl;
    }
}
