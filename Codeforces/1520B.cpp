#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    vector<int> a;
    a.push_back(0);
    for (int i = 1; i < 10; i++)
    {
        a.push_back(a[i-1] + 9);
    }
    while(tc--)
    {
        int n;
        cin >> n;
        int len = to_string(n).size();
        int ans = 0;
        ans += a[len-1];
        string str (len, '1');
        int x = str.size() == 0 ? 1 : stoi(str);
        //n -= len == 1 ? 0 :pow(10, len-1);
        ans += n / x;
        cout << ans << endl;
    }
}
