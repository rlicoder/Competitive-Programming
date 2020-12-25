#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int upper, lower;
    upper = lower = 0;
    for (int i = 0; i <str.size(); i++)
    {
        if (str[i] >= 'a')
        {
            lower++;
        }
        else
        {
            upper++;
        }
    }
    if (upper > lower)
    {
        for (int i = 0; i < str.size(); i++)
        {
            str[i] = toupper(str[i]);
        }
    }
    else
    {
        for (int i = 0; i < str.size(); i++)
        {
            str[i] = tolower(str[i]);
        }
    }
    cout << str << endl;
}
