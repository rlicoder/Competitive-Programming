#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    set<char>s;
    for (int i = 0; i < (int)str.size(); i++)
    {
        s.insert(str[i]);
    }
    if (s.size() == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < str.size()-1; i++)
        {
            if (str[i] != str[i+1])
            {
                cout << str[i] << str[i+1] << endl;
                break;
            }
        }
    }
}
