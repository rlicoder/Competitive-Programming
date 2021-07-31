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
        string s = str;
        sort(s.begin(), s.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != str[i])
            {
                count++;
            }
        }
        cout << count << endl;
    }
}
