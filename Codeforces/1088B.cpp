#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> s;
    int low = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int count = 0;
    auto it = s.begin();
    for (int i = 0; i < k; i++)
    {
        if (it == s.end())
        {
            cout << 0 << endl;
            continue;
        }
        cout << abs(low - *it) << endl;
        low = *it;
        it++;
        if (it == s.end())
        {
            continue;
            cout << 0 << endl;
        }
    }
}

