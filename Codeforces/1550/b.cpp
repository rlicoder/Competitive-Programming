#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;
        int numblocks = unique(str.begin(), str.end()) - str.begin();
        int ans = n*a;
        if (b >= 0)
        {
            ans += n*b;
        }
        else
        {
            int count = numblocks / 2 + 1;
            ans += b * count;
        }
        cout << ans << endl;
    }
}
