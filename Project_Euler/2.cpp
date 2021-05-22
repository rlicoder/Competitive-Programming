#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    int i = 2;
    while (true)
    {
        int add = a[i-1] + a[i-2];
        i++;
        a.push_back(add);
        if (add > 4e6)
        {
            break;
        }
    }
    for (auto it : a)
    {
        if (it % 2 == 0)
        {
            ans += it;
        }
    }
    cout << ans;
}
