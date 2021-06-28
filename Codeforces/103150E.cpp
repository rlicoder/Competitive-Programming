#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;
        int count = 0;
        int ocount = 0;
        bool valid = false;
        for (int i = 0; i < n; i++)
        {
            if (t[i] == 'o')
            {
                valid = true;
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
