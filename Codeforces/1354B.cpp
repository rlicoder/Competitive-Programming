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
        vector<pair<char,int>> a;
        int count = 1;
        char c = str[0];
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] == c)
            {
                count++;
            }
            else
            {
                a.push_back({c,count});
                c = str[i];
                count = 1;
            }
        }
        a.push_back({c,count});
        int ans = 2e9;
        //for (auto it : a)
        //{
        //    cout << it.first << "," << it.second << "  ";
        //}
        //cout << endl;
        if (a.size() < 3)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i <= a.size()-3; i++)
            {
                int sum = 0;
                for (int j = i; j < i+3; j++)
                {
                    sum += a[j].first - '0';
                }
                if (sum == 1+2+3)
                {
                    ans = min (ans, a[i+1].second + 2);
                }
            }
            if (ans == 2e9)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << ans << endl;
            }
        }
    }
}
