#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int k,n,m;
        cin >> k >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        vector<int> ans;
        int l, r;
        l = r = 0;
        bool valid = true;
        for (int i = 0; i < n+m; i++)
        {
            if (l < a.size() && a[l] == 0)
            {
                ans.push_back(a[l]);
                l++;
                k++;
            }
            else if (r < b.size() && b[r] == 0)
            {
                ans.push_back(b[r]);
                r++;
                k++;
            }
            else
            {
                if (l < a.size() && r < b.size())
                {
                    if (a[l] <= b[r] && a[l] <= k)
                    {
                        ans.push_back(a[l]);
                        l++;
                    }
                    else if (b[r] < a[l] && b[r] <= k)
                    {
                        ans.push_back(b[r]);
                        r++;
                    }
                    else
                    {
                        valid = false;
                    }
                }
                else
                {
                    if (l < a.size())
                    {
                        if (a[l] <= k)
                        {
                            ans.push_back(a[l]);
                            l++;
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                    else if (r < b.size())
                    {
                        if (b[r] <= k)
                        {
                            ans.push_back(b[r]);
                            r++;
                        }
                        else
                        {
                            valid = false;
                        }
                    }
                    else
                    {
                        valid = false;
                    }
                }
            }
        }
        if (valid)
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
