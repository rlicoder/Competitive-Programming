#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
const ll mod = 1000000007;
 
using namespace std;
 
main()
{
    string str;
    cin >> str;
    set<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i]);
    }
    if (s.size() % 2)
    {
        cout << "IGNORE HIM!" << endl;
    }
    else
    {
        cout << "CHAT WITH HER!" << endl;
    }
}