#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    int size = str.size();
    int q, s;
    q = s = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '?')
        {
            q++;
        }
        else if (str[i] == '*')
        {
            s++;
        }
    }
    size -= 2*q;
    size -= 2*s;
    string ans = "";
    cerr << str.size() << " " << q << " " << s << endl;
    if (size < k && s != 0)
    {
        cerr << "using snowflake" << endl;
        //you can use snowflake to increase until valid
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '*')
            {
                for (int j = 0; j < need; j++)
                {
                    ans.push_back(str[i-1]);
                }
            }
            else if (str[i] == '?')
            {
                ans.pop_back();
            }
            else
            {
                ans += str[i];
            }
        }
    }
    else if (k == size)
    {
        cerr << "no change needed" << endl;
        //no change needed
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '*' && str[i] != '?')
            {
                ans.push_back(str[i]);
            }
        }
    }
    else if (k < size)
    {

    }
    else
    {
        cout << "Impossible";
        exit(0);
    }
    cout << ans << endl;
}
