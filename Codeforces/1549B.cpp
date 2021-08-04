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
        string s1,s2;
        cin >> s1 >> s2;
        int ans = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s2[i] == '1')
            {
                if (i > 0 && s1[i-1] == '1')
                {
                    s1[i-1] = '2';
                    ans++;
                }
                else if (s1[i] == '0')
                {
                    s1[i] = '2';
                    ans++;
                }
                else if (i < n-1 && s1[i+1] == '1')
                {
                    s1[i+1] = '2';
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
