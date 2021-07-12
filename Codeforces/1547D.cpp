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
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i < n; i++)
        {
            bitset<32> b(a[i-1]);
            bitset<32> c(a[i]);
            bitset<32> d(0);
            for (int j = 0; j < b.size(); j++)
            {
                if (b[j] == 1 && c[j] == 0)
                {
                    d[j] = 1;
                }
            }
            a[i] |= d.to_ulong();
            ans.push_back(d.to_ulong());
        }
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}
