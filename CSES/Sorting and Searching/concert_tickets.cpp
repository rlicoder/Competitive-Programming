#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }


    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = a.lower_bound( x);
        if (it == a.end())
        {
            cout << -1;
        }
        else
        {
            cout << *it;
            a.erase(it);
        }
        cout << endl;
    }
}
