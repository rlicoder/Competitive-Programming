#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, str1;
    cin >> str >> str1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != str1[i])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}
