#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int k;
    cin >> str >> k;
    int cur = str.length();
    int s, c;
    s = c = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '*')
        {
            cur--;
            s++;
        }
        else if (str[i] == '?')
        {
            cur--;
            c++;
        }
    }
    string ans = "";
    if (cur == k)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '*' && str[i] != '?')
            {
                ans += str[i];
            }
        }
    }
    else if (cur > k)
    {
        if (cur - (c+s) <= k)
        {
            int toremove = cur - k;
            for (int i = 0; i < str.size(); i++)
            {
                if (toremove > 0)
                {
                    if (str[i] == '?' || str[i] == '*')
                    {
                        toremove--;
                        ans.pop_back();
                    }
                }
                if (str[i] != '?' && str[i] != '*')
                {
                    ans += str[i];
                }
            }
        }
        else
        {
            ans = "Impossible";
        }
    }
    else 
    {
        if (s > 0)
        {
            int toadd = k - cur;
            for (int i = 0; i < str.size(); i++)
            {
                if (str[i] == '*' && toadd > 0)
                {
                    while (toadd > 0)
                    {
                        ans.push_back(ans.back());
                        toadd--;
                    }
                }
                if (str[i] != '?' && str[i] != '*')
                {
                    ans.push_back(str[i]);
                }
            }
        }
        else
        {
            cout << "Impossible";
        }
    }
    cout << ans << endl;
}
