#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        string ans = "";
        cin >> str;
        vector<set<int>> a(26, set<int>());
        for (int i = 0; i < str.size(); i++)
        {
            char c = str[i];
            int count = 0;
            while (i < str.size() && str[i] == c)
            {
                i++;
                count++;
            }
            i--;
            a[c-'a'].insert(count);
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].size() >= 1)
            {
                bool odd = false;
                for (auto it : a[i])
                {
                    if (it % 2 == 1)
                    {
                        odd = true;
                        break;
                    }
                }
                if (odd)
                {
                    ans += 'a' + i;
                }
            }
        }
        cout << ans << endl;
    }
}
