#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> a(n+1, vector<pair<int,int>>());
    for (int i = 0; i < m; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = s.top();
        s.pop();
        for (auto it : a[cur])
        {

        }
    }

}
