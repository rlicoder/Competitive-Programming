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

        bool one = false;
        bool valid = true;
        for (int i = 0; i < str.size()-1; i++)
        {
            if (str.substr(i, 2) == "11") one = true;
            if (str.substr(i, 2) == "00")
            {
                if (one)
                {
                    valid = false;
                }
            }
        }
        if (valid)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;

    }
}
