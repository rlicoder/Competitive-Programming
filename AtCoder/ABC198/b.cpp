#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    while (str.back() == '0')
    {
        str.pop_back();
    }
    string rev = str;
    reverse(rev.begin(), rev.end());
    if (str == rev)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;
}
