#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    set<char>s;
    for (int i = 0; i < n; i++)
    {
        s.insert(str[i]);
    }
    if (n <= 26)
    {
        cout << n - (int)s.size() << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
