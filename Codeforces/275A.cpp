#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> a(3, vector<int>(3, 1));
    function<void(int,int,int)> fswitch = [&] (int i, int j, int x)
    {
        for (int c = 0; c < x; c++)
        {
            a[i][j] ^= 1;
            if (i+1 < 3)
                a[i+1][j] ^= 1;
            if (i-1 >= 0)
                a[i-1][j] ^= 1;
            if (j+1 < 3)
                a[i][j+1] ^= 1;
            if (j-1 >= 0)
                a[i][j-1] ^= 1;
        }
    };
    for (int i = 0 ; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            fswitch(i,j,x);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}
