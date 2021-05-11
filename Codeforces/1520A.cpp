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
        vector<bool> vis(26, false);
        bool valid = true;
        for (int i = 0; i < str.size(); i++)
        {
            if (vis[str[i]-'A'])
            {
                valid = false;
                break;
            }
            else
            {
                vis[str[i]-'A'] = true;
                i++;
                while (i < n && str[i] == str[i-1])
                {
                    i++;
                }
                i--;
            }
        }
        cout << (valid ? "Yes" : "No") << endl;
    }
}
