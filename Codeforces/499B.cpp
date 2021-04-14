#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,y;
    cin >> n >> y;
    map<string,string> m;
    for (int i = 0; i < y; i++)
    {
        string str,s;
        cin >> str >> s;
        m[str] = s;
    }
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str.size() <= m[str].size())
        {
            cout << str;
        }
        else
        {
            cout << m[str];
        }
        cout << " ";
    }
}
