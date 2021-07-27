#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    int i = 0;
    for (; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            break;
        }
    }
    if (i % 2 == 0)
    {
        cout << "Takahashi";
    }
    else
    {
        cout << "Aoki";
    }
    cout << endl;
}
