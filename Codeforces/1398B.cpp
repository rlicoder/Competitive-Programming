#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;
        vector<int> len;
        int count = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '1')
            {
                count++;
            }
            else
            {
                len.push_back(count);
                count = 0;
            }
        }
        if (count > 0)
        {
            len.push_back(count);
        }
        int ans = 0;
        sort(len.begin(), len.end(), greater<int>());
        for (int i = 0; i < len.size(); i+=2)
        {
            ans += len[i];
        }
        cout << ans << endl;
    }
}
