#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    int count = 0;
    int acount, fcount;
    acount = fcount = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'I')
        {
            count++;
        }
        else if (str[i] == 'A')
        {
            acount++;
        }
        else
        {
            fcount++;
        }
    }
    if (count >= 2)
    {
        cout << 0 << endl;
    }
    else if (count == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << acount << endl;
    }
}
