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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        set<int> s;
        vector<int> b,c;
        for (int i = 0; i < n; i++)
        {
            if (!s.count(a[i]))
            {
                b.push_back(a[i]);
            }
            else
            {
                c.push_back(a[i]);
            }
            s.insert(a[i]);
        }
        //for (auto it : b)
        //{
        //    cout << it << " ";
        //}
        //cout << endl;
        //for (auto it : c)
        //{
        //    cout << it << " ";
        //}
        //cout << endl;
        int ans = 0;
        int i = 0;
        while (binary_search(b.begin(), b.end(), i))
        {
            i++;
        }
        ans += i;
        i = 0;
        while (binary_search(c.begin(), c.end(), i))
        {
            i++;
        }
        ans += i;
        cout << ans << endl;
    }
}
