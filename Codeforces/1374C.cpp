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
        string str;
        cin >> str;
        int level = 0;
        int ans = 0;
        int a = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                level++;
            }
            else
            {
                level--;
            }
            if (level == a)
            {
                a--;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
