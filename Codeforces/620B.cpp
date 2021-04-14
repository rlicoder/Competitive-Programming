#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    string str = "";
    map<char,int> m;
    char c = '0';
    m[c++] = 6;
    m[c++] = 2;
    m[c++] = 5;
    m[c++] = 5;
    m[c++] = 4;
    m[c++] = 5;
    m[c++] = 6;
    m[c++] = 3;
    m[c++] = 7;
    m[c++] = 6;

    for (int i = a; i <= b; i++)
    {
        str += to_string(i);
    }
    long long ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        ans += m[str[i]];
    }
    cout << ans << endl;
}
