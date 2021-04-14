#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str >> str;
    int suma, sumb;
    suma = sumb = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '4' && str[i] != '7')
        {
            cout << "NO";
            return 0;
        }
        if (i < str.size()/2)
        {
            suma += str[i];
        }
        else
        {
            sumb += str[i];
        }
    }
    if (suma == sumb)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;

}
