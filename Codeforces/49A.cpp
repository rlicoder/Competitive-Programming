#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    char c = str[str.size()-2];
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u' || c == 'y')
    {
        cout << "YES";
    }
    else
    {
        cout <<"NO";
    }
}

