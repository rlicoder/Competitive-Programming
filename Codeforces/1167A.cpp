#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n; string str;
        cin >> n >> str;
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '8')
            {
                if (n-i >= 11)
                {
                    found = true;
                }
                else
                {
                    found = false;
                }
                break;
            }
            
        }
        cout << (found ? "YES" : "NO");
        cout << endl;
    }
}
        
