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
        int count = 1;
        n -= 1;
        for (int i = 3; n != 0; i += 2)
        {
            if (n - i >= 0)
            {
                n -= i;
                count++;
            }
            else
            {
                while (n - i < 0)
                {
                    i -= 1;
                }
                n -= i;
                count++;
            }
        }
        cout << count << endl;
    }
}
