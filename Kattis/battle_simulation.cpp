#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    map<char,char> map;
    map['R'] = 'S';
    map['B'] = 'K';
    map['L'] = 'H';
    set<char> s;
    string st = "";
    for (int i = 0; i < n; i++)
    {
        s = set<char>();
        st = "";
        for (int j = i; j < i+3 && j < n; j++)
        {
            s.insert(map[str[j]]);
            st += map[str[j]];
        }
        if (s.size() == 3)
        {
            cout << "C";
            i+=2;
        }
        else
        {
            cout << st[0];
        }
    }
}
