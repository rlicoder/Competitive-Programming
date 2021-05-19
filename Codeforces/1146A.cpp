#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;;
    cin >> str;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            count++;
        }
    }
    if (count > (str.size() + 1) / 2)
    {
        cout << str.size() << endl;
    }
    else
    {
        cout << str.size() - ((str.size() - count) - count + 1) << endl;
    }


}
