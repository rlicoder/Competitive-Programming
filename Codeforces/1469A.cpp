#include<bits/stdc++.h>

using namespace std;
 

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;
        if (str.size() % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        int add = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '?')
            {
                char c = add < str.size()/2-1 ? '(' : ')';
                add++;
                str[i] = c;
            }
        }
        int ans = 0;

        bool found = true;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                ans++;
            }
            else
            {
                ans--;
            }
            if (ans < 0)
            {
                found = false;
            }
        }
        if (found)
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
