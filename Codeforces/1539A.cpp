#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,x,t;
        cin >> n >> x >> t;

        long long ans = 0;
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++)
        {
            int start = i * x;
            int end = (i+1) * t;
            a.push_back({start,end});
        }
        for (int i = 0; i < n; i++)
        {
            int start = i * x;
            int end = (i+1) * t;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j].second < end && start >= a[j].first && i != j)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
