#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,q;
        cin >> n >> q;
        string str;
        cin >> str;
        while (q--)
        {
            int l,r;
            cin >> l >> r;
            string s = str.substr(l-1,(r-l+1));
           // cout << s << " ";
            if (abs(l-r) == 0)
            {
                cout << "NO" << endl;
                continue;
            }
            else if (r-l+1 == str.size())
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                bool lfound, rfound;
                rfound = lfound = false;
                char left = s[0];
                char right  = s[s.size()-1];
             //   cout << left << " " << right << endl;
                for(int i = 0; i < l-1; i++)
                {
                    if (str[i] == left)
                    {
                        lfound = true;
                        break;
                    }
                }
                for (int i = r; i < str.size(); i++)
                {
                    if (str[i] == right)
                    {
                        rfound = true;
                        break;
                    }
                }
                if (lfound || rfound)
                {
                    cout << "YES";
                }
                else
                {
                    cout << "NO";
                }
                cout << endl;
            }
        }
    }
}



