#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str(2e5, ' ');
    str[0] = str[2] = '9';
    str[1] = '8';
    char x = '0';
    for (int i = 3; i < str.size(); i++)
    {
        str[i] = x++;
        if (x > '9')
        {
            x = '0';
        }
    }
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << str.substr(0,n) << endl;
    }
}
