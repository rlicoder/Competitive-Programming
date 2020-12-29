#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        set<int>s;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n+m; i++)
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        cout << (n+m) - s.size() << endl;
    }
}
