#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int count = 0;
    string str = to_string(n);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '4' || str[i] == '7')
        {
            count++;
        }
    }
    bool ok = true;
    string st = to_string(count);
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] != '4' && st[i] != '7')
        {
            ok = false;
        }
    }
    if (ok)
    {
        cout <<"YES";
    }
    else
    {
        cout << "NO";
    }
}








            
            
    
