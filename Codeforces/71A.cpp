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
        if (str.size() > 10)
        {
            cout << str[0];
            cout << str.size()-2;
            cout << str[str.size()-1];
        }
        else
        {
            cout << str;
        }
        cout << endl;
    }
}
