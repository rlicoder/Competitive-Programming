#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0)
        {
            s.insert(i);
        }
    }
    for (auto it : s)
    {
        reverse(str.begin(), str.begin() + it);
    }
    cout << str << endl;
}
