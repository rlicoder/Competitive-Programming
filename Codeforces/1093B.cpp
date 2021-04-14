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
        sort(str.begin(), str.end());
        string s = str;
        reverse(s.begin(), s.end());
        if (s == str)
        {
            cout << - 1 << endl;
            continue;
        }
        else
        {
            cout << str << endl;
        }
    }
}
