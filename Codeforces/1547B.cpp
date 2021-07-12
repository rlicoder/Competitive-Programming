#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int l, r;
        l = r = -1;
        bool valid = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'a')
            {
                l = i - 1;
                r = i + 1;
                valid = true;
            }
        }
        for (char cur = 'b'; cur < str.size() + 'a'; cur++)
        {
            if (str[l] == cur)
            {
                l--;
            }
            else if (str[r] == cur)
            {
                r++;
            }
            else
            {
                valid = false;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
}
