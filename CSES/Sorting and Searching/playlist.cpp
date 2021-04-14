#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    int ans = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (s.count(a[i]) == 0)
        {
            s.insert(a[i]);
        }
        else
        {
            while (a[start] != a[i])
            {
                s.erase(a[start]);
                start++;
            }
            s.erase(a[start]);
            s.insert(a[i]);
            start++;
        }
//        for (auto it = s.begin(); it != s.end(); it++)
//        {
//            cout << *it << " ";
//        }
//        cout << endl;
        ans = max(ans, (int)s.size());

    }
    cout << ans << endl;
}
