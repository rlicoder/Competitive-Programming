#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> ans;
    for (int i = 100; i <= 999; i++)
    {
        for (int j = 100; j <= 999; j++)
        {
            string str = to_string(i*j);
            string s = str;
            reverse(s.begin(), s.end());
            if (s == str)
            {
                ans.push_back(i*j);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.back();
}
