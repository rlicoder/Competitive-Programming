#include <bits/stdc++.h>

using namespace std;

const string YES = "DA";
const string NO = "NET";

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;
        int zero, one;
        one = zero = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
            {
                zero++;
            }
            else
            {
                one++;
            }
        }
        if (min(zero,one)%2)
        {
            cout << YES << endl;
        }
        else
        {
            cout << NO << endl;
        }
    }
}
       
