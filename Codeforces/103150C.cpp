#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        //if p or c between e and z, impossible
        //if c before p, impossible
        int e,z,p,c;
        bool valid = true;
        for (int i = 0; i < str.size(); i++)
        {
            switch(str[i])
            {
                case 'p':
                    p = i;
                    break;
                case 'e':
                    e = i;
                    break;
                case 'z':
                    z = i;
                    break;
                case 'c':
                    c = i;
                    break;
                default:
                    break;
            }
        }
        if (c < e || c < p || p < z || c < z)
        {valid = false;}
        cout << (valid ? "YES" : "NO") << endl;
    }


}
