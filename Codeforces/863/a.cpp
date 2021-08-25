#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    bool valid = false;
    string t = str;
    reverse(t.begin(), t.end());
    if (t == str)
    {
        valid = true;
    }
    while (!valid && str.back() == '0')
    {
        str.pop_back();
        string t = str;
        reverse(t.begin(), t.end());
        if (t == str)
        {
            valid = true;
        }
    }
    cout << (valid ? "YES" : "NO");
}
