#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        vector<long long> c(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        stack<array<long long, 5>> q;
        q.push({0,0,0,0,0});
        long long ans = n*c[0] + n*c[1];
        while (!q.empty())
        {
            long long x = q.top()[0];
            long long y = q.top()[1];
            long long cost = q.top()[2];
            long long dir = q.top()[3];
            long long cur = q.top()[4];
            //cout << "x: " << x << endl;
            //cout << "y: " << y << endl;
            //cout << "cost: " << cost << endl;
            //cout << "dir: " << dir << endl;
            //cout << "cur: " << cur << endl;
            //cout << endl;
            q.pop();
            if (x == n && y == n)
            {
                ans = min(ans, cost);
            }
            else if (dir == 1)
            {
                if (cur == n-1 && n-x > 0 && n-y > 0)
                    continue;
                for (long long i = n-y; i > 0; i--)
                {
                    if (cost + i*c[cur] > ans)
                    {
                        continue;
                    }
                    q.push({x,y+i,cost+(i*c[cur]), 2, cur+1});
                }
            }
            else if (dir == 2)
            {
                if (cur == n-1 && n-x > 0 && n-y > 0)
                    continue;
                for (long long i = n-x; i > 0; i--)
                {
                    if (cost + i*c[cur] > ans)
                    {
                        continue;
                    }
                    q.push({x+i,y,cost+(i*c[cur]), 1, cur+1});
                }
            }
            else
            {
                for (long long i = 1; i <= n; i++)
                {
                    q.push({x+i, y, i*c[cur], 1, cur+1});
                }
                for (long long i = 1;i <= n; i++)
                {
                    q.push({x, y+i, i*c[cur], 2, cur+1});;
                }
            }
        }
        cout << ans << endl;
    }

}
