#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l, n, m;
    cin >> l >> n >> m;
    if (l == 8)
    {
        if (n < 2 || m < 2)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < 8/2; i++)
            {
                cout << 1 << " " << 2 << " ";
            }
            cout << endl;
            for (int i = 0; i < 8/2; i++)
            {
                cout << 2 << " " << 1 << " ";
            }
        }
    }
    else
    {
        if (n < 3 || m < 3)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < 9/3; i++)
            {
                cout << "1 2 3 ";
            }
            cout << endl;
            for (int i = 0; i < 9/3; i++)
            {
                cout << "2 3 1 ";
            }
            cout << endl;
        }
    }
}
