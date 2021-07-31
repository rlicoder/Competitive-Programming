#include <bits/stdc++.h>

using namespace std;

struct ft2d
{
    int n;
    vector<vector<int>> a;
    ft2d(int n) : a(n, vector<int>(n,0)), n(n) {};
    void update(int x, int y, int val)
    {
        for (int i = x; i <= n; i += (i & (-i)))
        {
            for (int j = y; j <= n; (j += j & (-j)))
            {
                a[i][j] += val;
            }
        }
    }
    int query(int x, int y)
    {
        int sum = 0;
        for (int i = x; i > 0; i -= (i & (-i)))
        {
            for (int j = y; j > 0; j -= (j & (-j)))
            {
                sum += a[i][j];
            }
        }
        return sum;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    ft2d ft(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            cin >> x;
            if (x == '*')
            {
                ft.update(i, j, 1);
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y,x;
            cin >> y >> x;
            if (ft.query(y,x) - ft.query(y-1,x) - ft.query(y,x-1) + ft.query(y-1,x-1))
            {
                ft.update(y,x,-1);
            }
            else
            {
                ft.update(y,x,1);
            }
        }
        else
        {
            int y1,x1,y2,x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << ft.query(y2,x2) - ft.query(y1-1,x2) - ft.query(y2, x1-1) + ft.query(y1-1,x1-1) << endl;
        }

    }

}
