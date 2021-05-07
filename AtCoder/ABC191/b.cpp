#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    bool found = true;
    for (int i = 0; i < str.size(); i+=2)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {

        }
        else
        {
            found = false;
        }
    }
    for (int i = 1; i < str.size(); i+=2)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            found = false;
        }
    }
    cout << (found ? "Yes" : "No");
}
