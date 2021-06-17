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
        if (a.size() < 3)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int i = 0; i < a.size()-3; i++)
            {
                int sum = 0;
                for (int j = i; j < i+3; j++)
                {
                    sum += a[j].second;
                }
                ans = min(ans, sum);
            }
        }
        cout << ans << endl;
    }
}
