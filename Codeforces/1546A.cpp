#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int x,y;
        x = y = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            x += a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            y += b[i];
        }
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            t += abs(a[i]-b[i]);
        }
        //le paranoia
        if (t/2 > 100)
        {
            cout << "REEE";
        }
        if (x != y)
        {
            cout << -1 << endl;
        }
        else
        {
            function<int(int, bool)> nextj = [&] (int x, bool add)
            {
                for (int i = 0; i < n; i ++)
                {
                    if (i == x)
                    {
                        continue;
                    }
                    if (add && a[i] < b[i])
                    {
                        return i;
                    }
                    else if (!add && a[i] > b[i])
                    {
                        return i;
                    }
                }
                return -1;
            };
            vector<pair<int,int>> ans;
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                while (a[i] != b[i])
                {
                    if (a[i] > b[i])
                    {
                        a[i]--;
                        j = nextj(i, true);
                        a[j]++;
                        ans.push_back({i+1,j+1});
                    }
                    else
                    {
                        a[i]++;
                        j = nextj(i, false);
                        a[j]--;
                        ans.push_back({j+1,i+1});
                    }
                }
            }
            cout << ans.size() << endl;
            for (auto [x,y] : ans)
            {
                cout << x << " " << y << endl;
            }
        }
    }
}
