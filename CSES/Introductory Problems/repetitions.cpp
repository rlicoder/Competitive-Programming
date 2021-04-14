#include <bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl '\n'
 
const int mod = 1000000007;
const int INF = INT_MAX;
 
using namespace std;
 
main()
{
    string str;
    cin >> str;
    int count = 1;
    int max = 1;
    char dummy = str[0];
    
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == dummy)
        {
            count++;
        }
        else
        {
            dummy = str[i];
            count = 1;
        }
        if (count > max)
        {
            max = count;
        }
    }
    cout << max << endl;
}
