#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>a(n);
    vector<int>t(m);
    set<int> s;
    bool valid = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i];)
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
        if (s.count(t[i]) == 0)
        {
            valid = false;
        }
    }
    if (valid)
    {

    }
    else
    {
        cout << -1 << endl;
    }

}
