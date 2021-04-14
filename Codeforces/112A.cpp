#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str, str1;
    cin >> str >> str1;
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
        str1[i] = tolower(str1[i]);
    }
    const char* cstr = str.c_str();
    const char* cstr1 = str1.c_str();
    int ans = strcmp(cstr, cstr1);
    if (ans < 0)
    {
        ans = -1;
    }
    cout << ans;
}
