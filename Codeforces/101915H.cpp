#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,k;
        cin >> n >> k;
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            vector<int> a(3);
            for (int i = 0; i < 3; i++)
            {
                cin >> a[i];
            }
            sort(a.begin(), a.end());
            pq.push(a[0]);
            pq.push(a[1]);
        }
        int ans = 0;
        while (k > 0)
        {
            k--;
            ans += pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}

