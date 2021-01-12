#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    set<int>s;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int x = b[i];
        if (s.count(x) == 1)
        {
            cout << 0 << " ";
            continue;
        }
        int count = 0;
        while (a[cur] != x)
        {
            count++;
            s.insert(a[cur]);
            cur++;
        }
        s.insert(a[cur]);
        cout << ++count << " ";
        cur++;
    }
}
