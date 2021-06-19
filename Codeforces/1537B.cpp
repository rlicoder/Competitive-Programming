#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n, m, x, y;
        cin >> n >> m >> x >> y;
        //choose any two polong longs with the greatest manhattan distance
        vector<pair<long long,long long>> a;
        //four corners
        a.push_back(make_pair(n, 1));
        a.push_back(make_pair(1, m));
        a.push_back(make_pair(1, 1));
        a.push_back(make_pair(n, m));

        //plus symbol
        a.push_back({n, y});
        a.push_back({x, m});
        a.push_back({1, y});
        a.push_back({x, 1});


        function<long long(pair<long long,long long>, pair<long long,long long>)> mand = [&] (pair<long long,long long> a, pair<long long,long long> b)
        {
            long long x = abs(a.first - b.first) + abs(a.second - b.second);
            return x;
        };

        function<bool(pair<long long,long long>, pair<long long,long long>)> comp = [&] (pair<long long,long long> a, pair<long long,long long> b)
        {
            long long da, db;
            da = abs(a.first - x) + abs(a.second - y);
            db = abs(b.first - x) + abs(b.second - y);
            return da < db;
        };

        vector<pair<long long,long long>> ans;
        long long hi = -1;
        long long tot = 0;
        for (long long i = 0; i < a.size(); i++)
        {
            for (long long j = i+1; j < a.size(); j++)
            {
                tot = 0;
                tot += mand(a[i], a[j]);
                tot += mand({x,y}, a[i]);
                tot += mand({x,y}, a[j]);
                if (tot > hi)
                {
                    hi = tot;
                    ans.clear();
                    ans.push_back(a[i]);
                    ans.push_back(a[j]);
                }
            }
        }

        //cout << "value: " << tot << endl;
        cout << ans[0].first << " " << ans[0].second << " " << ans[1].first << " " << ans[1].second << endl;
    }
}
