#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,ss;
    cin >> s >> ss;
    reverse(s.begin(), s.end());
    reverse(ss.begin(), ss.end());
    int ans = s.size() + ss.size();
    int i = 0;
    int count = 0;
    int low = min(s.size(), ss.size());
    while (s[i] == ss[i] && i < low)
    {
        count++;
        i++;
    }
    cout << ans - (2*count);

}
