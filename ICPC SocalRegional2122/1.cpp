#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        vector<vector<int>> ans(4, vector<int>(4));
        for (int i = 0; i < str.size(); i++)
        {
            int x = str[i] - '0';
            for (int j = 0; j < 4; j++)
            {
                ans[i][j] = (x % 2);
                x /= 2;
            }
        }
        for (int j = 3; j >= 0; j--)
        {
            for (int i = 0; i < 4; i++)
            {
                if (i == 2) cout << " ";
                cout << (ans[i][j] ? '*' : '.');
            }
            cout << endl;
        }
    }
}
