#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, s;
    cin >> str >> s;
    int n = s.length();
    int ans = 0;
    if (n > str.size())
    {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 0; i <= str.size()-n; i++)
    {
        if (str.substr(i, n) == s)
        {
            ans++;
            str[i+n-1] = '#';
        }
    }
    cout << ans << endl;
    cerr << str << endl;
}
