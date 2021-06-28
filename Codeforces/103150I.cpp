#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long a,b;
        cin >> a >> b;
        bitset<64> x(a);
        bitset<64> y(b);

        bitset<64> ans(0LL);

        bool valid = true;
        for (int i = 0; i < 64; i++)
        {
            if (x[i] == 1 && y[i] == 0)
            {
                ans[i] = 1;
            }
            else if (x[i] && y[i])
            {
                ans[i] = 0;
            }
            else if (!x[i] && !y[i])
            {
                ans[i] = 0;
            }
            else
            {
                valid = false;
            }
        }
        if (valid)
        {
            cout << ans.to_ullong();
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}
