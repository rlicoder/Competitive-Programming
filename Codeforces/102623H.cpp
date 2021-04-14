#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, long long>>> arr(n, vector<pair<long long, long long>>(m,{0,0}));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j].first;
            arr[i][j].first %= mod;
        }
    }
    long long ans = 0;
    for (int i = 0; i < k; i++)
    {
        char c;
        cin >> c;
        long long x,p;
        cin >> x >> p;
        p %= mod;
        if (c == 'r')
        {
            for (int i = 0; i < m; i++)
            {
                ans = (ans + ((arr[x-1][i].first) * ((p - (arr[x-1][i].second) + mod) % mod))) % mod;
                arr[x-1][i].second = p;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans = (ans + ((arr[i][x-1].first) * ((p - (arr[i][x-1].second) + mod) % mod))) % mod;
                arr[i][x-1].second = p;
            }
        }
    }
    cout << ans%mod << '\n';
}



