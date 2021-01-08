#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    string ans = "";
    bool flag = (str.size() % 2 == 0 ? false : true);
    for (int i = 0; i < str.size(); i++)
    {
        if (flag)
        {
            ans += str[i];
        }
        else
        {
            ans.insert(0,1,str[i]);
        }
        //cout << ans << endl;
        flag = !flag;
    }
    cout << ans << endl;
}
