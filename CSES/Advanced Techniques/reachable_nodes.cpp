#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    const int mx = 7;
    vector<pair<bitset<mx>,int>> a(n);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < a.size(); i++)
    {
        a[i].second = i;
        //a[i].first |= 1<<i;
    }
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        a[x].first |= 1<<y;
    }
    sort(a.begin(), a.end(), [&] (pair<bitset<mx>,int> x, pair<bitset<mx>,int> y) { return adj[x.second].size() < adj[y.second].size(); });
    //a[i] should store <bitset, index>
    for (auto it : a)
    {
        cout << it.first.to_string() << " " << it.second+1 << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i]) 
        {
            a[i].first |= a[it].first;
        }
    }
    sort(a.begin(), a.end(), [&] (pair<bitset<mx>,int> x, pair<bitset<mx>,int> y) { return x.second < y.second; });
    for (auto it : a)
    {
        cout << it.first.to_string() << " " << it.second+1 << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i].first.count()+1 << " ";
    }
}
