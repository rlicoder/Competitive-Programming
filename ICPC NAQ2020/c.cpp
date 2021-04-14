#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<char>> a(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> a[i][j];
        }
    }
    function<bool(int, int)> valid = [&](int x, int y)
    {
        for (int j = 0; j < 8; j++)
        {
            if (a[j][y] == '*' && j != x)
            {
                return false;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            if (a[x][i] == '*' && i != y)
            {
                return false;
            }
        }
        int ox, oy;
        ox = x; oy = y;
        int d = min(ox, oy);
        ox -= d; oy -= d;
        for (int i = ox, j = oy; i < 8 && j < 8; i++,j++)
        {
            if (a[i][j] == '*' &&  i != x && j != y)
            {
                return false;
            }
        }
        for (int i = x, j = y; i >= 0 && j < 8; i--,j++)
        {
            if (a[i][j] == '*' && i != x && j != y)
            {
                return false;
            }
        }
        for (int i = x, j = y; i < 8 && j >= 0; i++,j--)
        {
            if (a[i][j] == '*' && i != x && j != y)
            {
                return false;
            }
        }
        return true;
    };
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (a[i][j] == '*')
            {
                count++;
                if (!valid(i,j))
                {
                    cout << "invalid";
                    return 0;
                }
            }
        }
    }
    if (count == 8)
    {
        cout << "valid";
    }
    else
    {
        cout << "invalid";
    }
   
}

