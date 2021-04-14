#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(), a.end(), comp);
    int curr = a[0].second;
    int ans = 0;
    ans++;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first >= curr)
        {
            ans++;
            curr = a[i].second;
        }
    }
    cout << ans << endl;
}



