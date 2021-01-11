#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    set<char>s;
    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i]);
    }
    if(s.size() == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    string a = str;
    reverse(a.begin(), a.end());
    if (a == str)
    {
        cout << str.size() - 1 << endl;
    }
    else
    {
        cout << str.size() << endl;
    }
}
