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
        int even, odd;
        even=odd=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i]%2)
            {
                odd+;
            }
            else
            {
                even++;
            }
        }
        sort(a.begin(), a.end());

    }
}
