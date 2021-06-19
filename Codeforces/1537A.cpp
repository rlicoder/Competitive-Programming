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
        long double total = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            total += x;
        }
        if (total / n < 1.0)
        {
            cout << 1 << endl;
        }
        else if (float(total / n) > 1.0)
        {
            cout << total - n << endl;
        }
        else
        {
            cout << 0 << endl;
        }

    }

}
